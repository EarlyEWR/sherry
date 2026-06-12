#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
PACKAGE_NAME="${1:-telemetry_bridge}"
BUILD_TESTING="${BUILD_TESTING:-ON}"
IMAGE_NAME="${IMAGE_NAME:-telemetry-bridge:foxy}"
DOCKER_TEST_RUN="${DOCKER_TEST_RUN:-0}"

source_setup_file() {
  local setup_path="$1"

  set +u
  # ROS setup scripts may reference unset tracing variables.
  source "${setup_path}"
  set -u
}

run_tests() {
  echo "Building ${PACKAGE_NAME} with BUILD_TESTING=${BUILD_TESTING}"
  colcon build --packages-select "${PACKAGE_NAME}" --cmake-args "-DBUILD_TESTING=${BUILD_TESTING}"

  if [[ -f "${ROOT_DIR}/install/setup.bash" ]]; then
    source_setup_file "${ROOT_DIR}/install/setup.bash"
  fi

  echo "Running tests for ${PACKAGE_NAME}"
  colcon test --packages-select "${PACKAGE_NAME}"

  echo "Showing test results for ${PACKAGE_NAME}"
  colcon test-result --verbose
}

if [[ -f /opt/ros/foxy/setup.bash ]]; then
  # Load the ROS environment when running inside the project container.
  source_setup_file /opt/ros/foxy/setup.bash
fi

cd "${ROOT_DIR}"

if command -v colcon >/dev/null 2>&1; then
  run_tests
  exit 0
fi

if [[ "${DOCKER_TEST_RUN}" == "1" ]]; then
  echo "colcon was not found inside the Docker test environment." >&2
  exit 127
fi

if ! command -v docker >/dev/null 2>&1; then
  echo "colcon was not found and docker is not installed." >&2
  echo "Install ROS2/colcon locally or install Docker and rerun this script." >&2
  exit 127
fi

echo "colcon not found locally; running tests in Docker image ${IMAGE_NAME}"

if ! docker image inspect "${IMAGE_NAME}" >/dev/null 2>&1; then
  echo "Docker image ${IMAGE_NAME} not found; building it first"
  docker build -t "${IMAGE_NAME}" "${ROOT_DIR}"
fi

docker run --rm \
  -v "${ROOT_DIR}:/workspace" \
  -w /workspace \
  -e BUILD_TESTING="${BUILD_TESTING}" \
  -e DOCKER_TEST_RUN=1 \
  "${IMAGE_NAME}" \
  bash /workspace/scripts/test.sh "${PACKAGE_NAME}"

# If you want to target a different package later,
# it also accepts one optional package name: ./scripts/test.sh some_other_package

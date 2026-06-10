#!/usr/bin/env bash
set -euo pipefail

MODE="${1:-bridge}"                    # bridge (default) or host
IMAGE="${2:-telemetry-bridge:foxy}"    # optional image override
PORT="${PORT:-8091}"                   # optional UDP port override

case "$MODE" in
  bridge)
    echo "Mode: bridge | UDP port: $PORT | Image: $IMAGE"
    exec docker run --rm -p "${PORT}:${PORT}/udp" "$IMAGE"
    ;;
  host)
    echo "Mode: host | Image: $IMAGE"
    exec docker run --rm --network host "$IMAGE"
    ;;
  *)
    echo "Usage: $0 {bridge|host} [image]"
    echo "Example: $0 bridge telemetry-bridge:foxy"
    exit 1
    ;;
esac
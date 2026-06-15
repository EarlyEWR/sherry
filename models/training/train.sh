# Launch NGC PyTorch container and run training on the DGX Spark
# Usage (from repo root):
#   bash models/training/train.sh check       # verify GPU + architecture
#   bash models/training/train.sh preprocess  # SPEED+ JSON → YOLO labels
#   bash models/training/train.sh speed       # Stage 1: train on SPEED+
#   bash models/training/train.sh basilisk    # Stage 2: fine-tune on Basilisk renders

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
STAGE="${1:-check}"

case "$STAGE" in
    check|preprocess|speed|basilisk)
        docker compose \
            -f "${REPO_ROOT}/models/training/docker-compose.training.yaml" \
            --profile "${STAGE}" \
            up --abort-on-container-exit
        ;;
    *)
        echo "Usage: $0 [check|preprocess|speed|basilisk]"
        exit 1
        ;;
esac
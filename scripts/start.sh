#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
COMPOSE_FILE="${ROOT_DIR}/docker-compose.yaml"
MODE="${1:-bridge}"

case "$MODE" in 
    bridge)
        exec docker compose -f "${COMPOSE_FILE}" --profile bridge up --build
        ;;
    host)
        exec docker compose -f "${COMPOSE_FILE}" --profile host up --build
        ;;
    *)
    echo "Usage: $0 {bridge|host}"
    ;;

esac
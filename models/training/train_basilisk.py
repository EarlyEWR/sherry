"""
Stage 2: Fine-tune SPEED+ weights onto Basilisk renders.
Run via: bash models/training/train.sh basilisk

Requires: models/weights/yolo_speed/weights/best.pt  (yolov12l backbone, from train_speed.py)
Output:   models/weights/yolo_docking.pt              (loaded by cv_pipeline_node.py)
"""
import shutil
from pathlib import Path
from ultralytics import YOLO

REPO_ROOT = Path(__file__).resolve().parents[2]
STAGE1_WEIGHTS = REPO_ROOT / 'models/weights/yolo_speed/weights/best.pt'
FINAL_WEIGHTS = REPO_ROOT / 'models/weights/yolo_docking.pt'


def main():
    if not STAGE1_WEIGHTS.exists():
        raise FileNotFoundError(
            f'Stage 1 weights not found at {STAGE1_WEIGHTS}\n'
            'Run train_speed.py first.'
        )

    model = YOLO(str(STAGE1_WEIGHTS))

    model.train(
        data=str(REPO_ROOT / 'models/training/basilisk_dataset.yaml'),
        epochs=50,
        batch=64,
        imgsz=640,
        device=0,
        workers=8,
        project=str(REPO_ROOT / 'models/weights'),
        name='yolo_basilisk',
        exist_ok=True,
        lr0=0.001,
        lrf=0.01,
        warmup_epochs=3,
        freeze=10,
    )

    best = REPO_ROOT / 'models/weights/yolo_basilisk/weights/best.pt'
    shutil.copy2(best, FINAL_WEIGHTS)
    print(f'Final weights written to {FINAL_WEIGHTS}')


if __name__ == '__main__':
    main()
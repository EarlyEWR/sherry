"""
Stage 1: Fine-tune YOLOv12l on SPEED+ synthetic dataset.
Run via: bash models/training/train.sh speed

Output: models/weights/yolo_speed/weights/best.pt
"""
from pathlib import Path
from ultralytics import YOLO

REPO_ROOT = Path(__file__).resolve().parents[2]


def main():
    model = YOLO('yolov12l.pt')  # large — safe on DGX Spark 128 GB unified memory

    model.train(
        data=str(REPO_ROOT / 'models/training/speed_dataset.yaml'),
        epochs=75,
        batch=128,
        imgsz=640,
        device=0,
        workers=8,
        project=str(REPO_ROOT / 'models/weights'),
        name='yolo_speed',
        exist_ok=True,
        # Augmentation to bridge the SPEED+ → Basilisk domain gap
        degrees=5.0,       # slight rotation (spacecraft tumble)
        translate=0.1,
        scale=0.3,         # approach distance variation
        fliplr=0.5,
        hsv_h=0.015,
        hsv_s=0.7,
        hsv_v=0.4,
    )


if __name__ == '__main__':
    main()
"""
Converts SPEED+ JSON pose labels into YOLO bounding box format

SPEED+ label format (train.json / validation.json):
  [{"filename": "img000001.jpg",
    "q_vbs2tango_true": [qx, qy, qz, qw],   # scalar-last quaternion
    "r_Vo2To_vbs_true": [tx, ty, tz]},        # meters, camera frame
   ...]

camera.json:
  {"fx": ..., "fy": ..., "cx": ..., "cy": ..., "nu": ..., "nv": ...}

tangoPoints.mat:
  tango3Dpoints: [3 x N] array of 3D keypoints in Tango body frame

Output YOLO label (one .txt per image):
  0 cx_norm cy_norm w_norm h_norm   (class 0 = tango, values normalised [0,1])

Usage (from repo root):
  python models/training/preprocess_speed.py
"""

import argparse
import json
import shutil
from pathlib import path

import numpy as np
import scipy.io
from scipy.spatial.transform import Rotation

def project_points(pts_3d, q_xyzw, t, fx, fy, cx, cy):
    """Project 3D body-frame keypoints to 2D pixel coordiantes"""
    R = Rotation.from_quat(q_xyzw).as_matrix()
    t = np.array(t).reshape(3, 1)
    pts_cam = R @ pts_3d + t

    valid = pts_cam[2] > 0
    u = fx * pts_cam[0, valid] / pts_cam[2, valid] + cx
    v = fy * pts_cam[1, valid] / pts_cam[2, valid] + cy
    return u, v

def bbox_from_projected(u, v, img_w, img_h):
    """Axis-aligned bbox clipped to image bounds. Returns None if off-screen"""
    if len(u) == 0:
        return None
    
    x_min = float(np.clip(np.min(u), 0, img_w))
    x_max = float(np.clip(np.max(u), 0, img_w))
    y_min = float(np.clip(np.min(v), 0, img_h))
    y_max = float(np.clip(np.max(v), 0, img_h))

    w = x_max - x_min
    h = y_max - y_min
    if w <= 0 or h <= 0:
        return None
    
    return (
        (x_min + x_max) / 2.0 / img_w, # cx normalized
        (y_min + y_max) / 2.0 / img_h, # cy normalized
        w / img_w,
        h / img_h,
    )

def preprocess(dataroot, tangopts_path, plit, outdir):
    dataroot = Path(dataroot)
    outdir = Path(outdir)

    with open(dataroot / 'camera.json') as f:
        cam = json.load(f)
    fx, fy, cx, cy = cam['fx'], cam['fy'], cam['cx'], cam['cy']
    img_w, img_h = int(cam['nu']), int(cam['nv'])

    mat = scipy.io.loadmat(tangopts_path)
    pts_3d = mat['tango3Dpoints'].astype(np.float64)
    if pts_3d.shape[0] != 3:
        pts_3d = pts_3d.T # normalize to (3, N)

    json_path = dataroot / 'synthetic' / f'{split}.json'
    with open(json_path) as f:
        labels = json.load(f)

    img_src = dataroot / 'synthetic' / 'images'
    img_out = outdir / 'images' / split
    img_out = outdir / 'labels' / split
    img_out.mkdir(parents=True, exist_ok=True)
    lbl_out.mkdir(parents=True, exist_ok=True)

    skipped = 0
    for entry in labels:
        filename = entry['filename']
        q = entry['q_vbs2tango_true'] # [qx, qy, qz, qw]
        t = entry['r_Vo2To_vbs_true']

        u, v = project_points(pts_3d, q, t, fx, fy, cx, cy)
        bbox = bbox_from_projected(u, v, img_w, img_h)

        if bbox is None:
            skipped += 1
            continue
    
        shutil.copy2(img_src / filename, img_out / filename)
        stem = Path(filename).stem
        with open(lbl_out / f'{stem}.txt', 'w') as f:
            f.write(f'0 {bbox[0]:.6f} {bbox[1]:.6f} {bbox[2]:.6f} {bbox[3]:.6f}\n')
    
    total = len(labels)
    print(f'{split}: {total - skipped}/{total} written ({skipped} skipped. All keypoints off-screen)')

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--dataroot', default='model/datasets/speedplus')
    parser.add_argument('--tangopts', default='models/training/tangoPoints.mat')
    parser.add_argument('--outdir', default='models/datasets/speedplus/yolo')
    args = parser.parse_args()

    for split in ('train', 'validation'):
        preprocess(args.dataroot, args.tangopts, split, args.outdir)

if __name__ == '__main__':
    main()
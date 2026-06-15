"""
Run inside the NGC container before training to verify
ARM64 / Grace Blackwell is correctly detected
"""

import platform
import sys
import torch

def main ():
    print(f'Python:         {sys.version}')
    print(f'Architecture:   {platform.machine()}') # aarch64
    print(f'PyTorch:        {torch.__version__}')
    print(f'CUDA available: {torch.cuda.is_available()}')

    if torch.cuda.is_available():
        for i in range(torch.cuda.device_count()):
            props = torch.cuda.get_device_properties(i)
            print(f'GPU {i}: {props.name} ({props.total_memory / le9:.1f} GB)')
            print(f' Compute capability: {props.major}.{props.minor}')
    else:
        print('WARNING: No CUDA device. Training will be CPU-only')
    
    try:
        import ultralytics
        print(f'Ultralytics: {ultralytics.__version__}')
    except ImportError:
        print('ERROR: ultralytics not installed')

if __name__ == '__main__':
    main()
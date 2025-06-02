# 🧠 System Programming - Optimized Image Convolution Filter

Author: 김창규 (202011061)  
Course: System Programming @ DGIST  

---

## 📌 Overview

This project implements an **optimized image convolution filter** using a custom 3×3 kernel, written in C. The goal is to process image data efficiently and apply performance improvement techniques at the system level.

The assignment includes:
- An image convolution filter operating on RGB channels.
- Execution time benchmarking using `perfenv.c`.
- Optimization techniques applied to maximize performance.

---

## 🖼️ Image Convolution Filter

### ✨ Key Features
- Applies **3×3 convolution kernel** to each pixel of the input image.
- Processes **RGB channels** (Red, Green, Blue) **separately**.
- Handles **image boundaries** correctly.
- Optimized for **efficient memory and cache access** patterns.

### 🧪 Performance Measurement
The filter is tested using a benchmarking environment (`perfenv.c`) that:
- Repeats the filtering process multiple times.
- Checks for **execution time convergence** to ensure reliable measurement.
- Compares execution time between baseline and optimized versions.

---

## 📈 Optimization Results

| Image Size | Speed-up (vs. Baseline) |
|------------|--------------------------|
| 1024×1024  | 2.84×                    |
| 768×768    | 2.40×                    |
| 512×512    | 2.40×                    |
| 256×256    | 2.38×                    |
| 128×128    | 2.36×                    |

The larger the image, the more significant the performance improvement due to better cache efficiency and loop optimization.

---

## 🔧 Optimization Techniques

### ✅ Memory & Cache Efficiency
- Removed unnecessary variable declarations and address allocations.
- Ensured **sequential memory access** to maximize spatial locality.

### ✅ Loop & Arithmetic Optimization
- **Loop unrolling** used to reduce control overhead.
- Simplified arithmetic operations, especially within loops.

### ✅ Data Size Minimization
- Used **smaller data types** wherever applicable.
- Shortened code to reduce instruction cache usage.

### ✅ Instruction Optimization
- Preferred simpler comparisons (e.g., `==`) over `>=`, `>`.
- Applied **function inlining** for frequently called short routines.

---


## 📂 File Structure

```
├── Makefile               # Build script
├── README.md              # Project description and documentation
├── bmplib.c               # BMP file handling (image I/O)
├── bmplib.h               # BMP header definitions
├── hw2.c                  # Optimized convolution filter implementation
├── hw2.h                  # Header for convolution functions
├── main.c                 # Entry point for executing the filter
├── perfenv.c              # Performance measurement environment
├── perfenv.h              # Header for performance environment
├── img_128.bmp            # Sample input image (128×128)
├── img_256.bmp            # Sample input image (256×256)
├── img_512.bmp            # Sample input image (512×512)
├── img_768.bmp            # Sample input image (768×768)
└── img_1024.bmp           # Sample input image (1024×1024)
```

---

## 📝 Notes

- Performance improvement is more evident with larger image sizes.
- This project emphasizes **low-level efficiency** and **code clarity**.

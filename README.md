# Image Convolution Filter

This project implements an optimized image convolution filter using a 3×3 kernel.  
It processes an input image by applying a custom 3×3 filter to each pixel and produces a filtered output image.

Key features:
- Applies convolution while handling image boundaries.
- Processes each RGB channel (red, green, blue) separately.
- Optimizes pixel access for better performance.

Additionally, the provided performance measurement tool (`perfenv.c`) is used to accurately measure the execution time of the filter function by running multiple trials and checking convergence.

This project is part of "Assignment 2 - Efficient C Programming" for the System Programming course at DGIST.

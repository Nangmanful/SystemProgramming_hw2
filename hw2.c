// Assignment 2 - Efficient C Programming
// System Programming, DGIST, Prof. Yeseong Kim
//
// YOU WILL TURN IN THIS FILE.
// Read the provided instruction carefully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmplib.h"
#include "hw2.h"

// This implementation is simply copied from "main.c".
// Your job is to modify and optimize it for better performance!

static inline void convolution(
        Pixel* input, int x, int y, int width, int height, float* filter, Pixel* output, int num) {
    int r = 0;
    int g = 0;
    int b = 0;

    for (int dy = -1; dy < 2; ++dy) {
        int tall = dy*width;
        for (int dx = -1; dx < 2; ++dx) {
            if ((y + dy) < 0 || (y + dy) >= height)
                continue;
            if ((x + dx) < 0 || (x + dx) >= width)
                continue;
            int num2 = num+dx+tall;
            int num1 = dx+4+dy*3;
            r += input[num2].r * filter[num1];
            g += input[num2].g * filter[num1];
            b += input[num2].b * filter[num1];
        }
    }

    if (r < 0) r = 0;
    if (g < 0) g = 0;
    if (b < 0) b = 0;

    if (r > 255) r = 255;
    if (g > 255) g = 255;
    if (b > 255) b = 255;

    output[num].r = r;
    output[num].g = g;
    output[num].b = b;
}

inline void filter_optimized(void* args[]) {
    unsigned int width = *(unsigned int*)args[0];
    unsigned int height = *(unsigned int*)args[1];
    Pixel* input = args[2];
    Pixel* output = args[3];
    float* filter = args[4];

    const int blockSize = 128;

    for (int by = 0; by < height; by += blockSize) {
        for (int bx = 0; bx < width; bx += blockSize) {
            for (int y = by; y < by + blockSize && y < height; ++y) {
                int tall = y * width;
                for (int x = bx; x < bx + blockSize && x < width; ++x) {
                    int num = x+tall;
                    convolution(input, x, y, width, height, filter, output, num);

                }
            }
        }
    }
}                                                                                                                                                                                                                                                                                                                                                          
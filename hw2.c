static void convolution(Pixel* input, int x, int y, int width, int height, float* filter, Pixel* output, int num) {
    double r = 0;
    double g = 0;
    double b = 0;

    int x_start = (x > 0) ? -1 : 0;
    int x_end = (x < width - 1) ? 2 : 1;
    int y_start = (y > 0) ? -1 : 0;
    int y_end = (y < height - 1) ? 2 : 1;

    for (int dy = y_start; dy < y_end; ++dy) {
        for (int dx = x_start; dx < x_end; ++dx) {
            int idx = (x + dx) + (y + dy) * width;
            int filter_idx = (dx + 1) * 3 + (dy + 1);
            r += input[idx].r * filter[filter_idx];
            g += input[idx].g * filter[filter_idx];
            b += input[idx].b * filter[filter_idx];
        }
    }

    if (r < 0) r = 0;
    if (g < 0) g = 0;
    if (b < 0) b = 0;
    if (r > 255) r = 255;
    if (g > 255) g = 255;
    if (b > 255) b = 255;

    output[num].r = (unsigned char)r;
    output[num].g = (unsigned char)g;
    output[num].b = (unsigned char)b;
}

void filter_optimized(void* args[]) {
    unsigned int width = *(unsigned int*)args[0];
    unsigned int height = *(unsigned int*)args[1];
    Pixel* input = args[2];
    Pixel* output = args[3];
    float* filter = args[4];

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int num = x + y * width;
            convolution(input, x, y, width, height, filter, output, num);
        }
    }
}

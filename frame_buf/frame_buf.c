#include <stdio.h>
#include <inttypes.h>

#define FRAME_HEIGHT 128
#define FRAME_WIDTH 30

static uint8_t FRAME_BUF[FRAME_HEIGHT][FRAME_WIDTH] = { 0 };

void draw_frame_buf(uint8_t invert) {
    for (size_t y = 0; y < FRAME_HEIGHT; y++) {
        for (size_t x = 0; x < FRAME_WIDTH; x++) {
            for (size_t bit = 0; bit < 8; bit++) {
                if (invert) {
                    printf("%s", FRAME_BUF[y][x] & (1<<bit) ? "_" : "X");
                } else {
                    printf("%s", FRAME_BUF[y][x] & (1<<bit) ? "X" : "_");
                }
            }
        }
        printf("\n");
    }
}

void plot_set_pixel(uint8_t state, uint8_t x, uint8_t y) {

    uint8_t ym = y % FRAME_HEIGHT;
    uint8_t xi = (x / 8) % FRAME_WIDTH;
    uint8_t xm = x % 8;

    if (state) {
        // Set pixel
        FRAME_BUF[ym][xi] |= (uint8_t)1<<xm;
    } else {
        // Clear pixel
        FRAME_BUF[ym][xi] &= ~((uint8_t)1<<xm);
    }

}

int main() {
    plot_set_pixel(1, 0, 127);
    plot_set_pixel(1, 1, 127);
    plot_set_pixel(1, 2, 127);
    plot_set_pixel(0, 1, 127);
    plot_set_pixel(1, 8, 127);
    plot_set_pixel(1, 239, 127);
    draw_frame_buf(0);
    return 0;
}

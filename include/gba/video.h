#pragma once

#include <stdint.h>

#define FB_WIDTH    (240)
#define FB_HEIGHT   (160)

#define FB_PIXEL(pfb, x, y) \
    ((pfb)->buf[(x) + ((y) * FB_WIDTH)]);

typedef uint16_t pixel;

struct framebuffer {
    pixel buf[FB_WIDTH * FB_HEIGHT];
};

/* Reference a pixel in a framebuffer given an x, y coordinate.
 * top left is 0,0 */
static inline pixel* getpixel(struct framebuffer *self, pixel x, pixel y)
{
    return &self->buf[x + (y * FB_WIDTH)];
}

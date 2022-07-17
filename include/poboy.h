#pragma once

#include "gba/cpu.h"
#include "gba/video.h"

struct gba {
    struct cpu cpu;
    struct framebuffer framebuffer;
};

/* Main emulator context */
struct poboy {
    struct gba gba;
};

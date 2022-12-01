#pragma once
#include <stdlib.h>

#include "../GPU.h"

class PiDDXRenderer{
    public:
        PiDDXRenderer();

        void render(u32* buf[2][2], int front_buffer);
    private:
        size_t count;

        char* bufCopy;
};
#include "renderer.h"
#include <iostream>
#include <png.h>

size_t Width = 256;
size_t Height = 192;
size_t SingleScreenSize = Width*Height;
PiDDXRenderer::PiDDXRenderer(){
    count = 0;

    bufCopy = (char*) malloc(2*SingleScreenSize*3*sizeof(char));
}

void PiDDXRenderer::render(u32* buf[2][2], int frontBuffer){
    // memcpy(bufCopy, buf[frontBuffer][0], SingleScreenSize * sizeof (u32));
	// memcpy(bufCopy + SingleScreenSize, buf[frontBuffer][1], SingleScreenSize * sizeof (u32));

    for(size_t of = 0; of < 2*SingleScreenSize; of++){
        u32* c_buf = NULL;
        size_t delta = 0;
        if(of < SingleScreenSize){
            c_buf = buf[frontBuffer][0];
        } else{
            c_buf = buf[frontBuffer][1];
            delta = SingleScreenSize;
        }
        u32 rgba = c_buf[of - delta];

        char b = (rgba << 4) % 256;
        char g = (rgba << 8) % 256;
        char r = (rgba << 16) % 256;

        bufCopy[3*of] = r;
        bufCopy[3*of + 1] = g;
        bufCopy[3*of + 2] = b;
    }
    count += 1;
}
//
// Created by Will&Carm on 11/12/2023.
//
#include "AsteriodGameScreen.h"
#include "ScreenRender.h"

void drawRect(f32 x, f32 y, f32 halfSizeX, f32 halfSizeY, u32 color) {
    // this is to make the rect independent so the rect will resize if the gui is resized

    x *= static_cast<f32>(renderState.bufferHeight) * renderScale;
    y *= static_cast<f32>(renderState.bufferHeight) * renderScale;
    halfSizeX *= static_cast<f32>(renderState.bufferHeight) * renderScale;
    halfSizeY *= static_cast<f32>(renderState.bufferHeight) * renderScale;
    // convert, * the rect with the screen width and height so tha the rect stays the same even if the gui size is changed

    x += static_cast<f32>(renderState.bufferWidth) /2.f;
    y += static_cast<f32>(renderState.bufferHeight) /2.f;
    // offsetting to the center of the screen can pass 0, 0 to center it

    // change to pixels
    s32 x0 = static_cast<s32>(x - halfSizeX);
    s32 x1 = static_cast<s32>(x + halfSizeX);
    s32 y0 = static_cast<s32>(y - halfSizeY);
    s32 y1 = static_cast<s32>(y + halfSizeY);
    // find the min max points

    //centre
    draw_rect_in_pixel(x0, y0, x1, y1, color);
}

void draw_rect_in_pixel(int x0, int y0, int x1, int y1, u32 color) {

    x0 = clamp(0, x0, renderState.bufferWidth);
    x1 = clamp(0, x1, renderState.bufferWidth);
    y0 = clamp(0, y0, renderState.bufferHeight);
    y1 = clamp(0, y1, renderState.bufferHeight);
    // it needs to be clamped or the program will crash because the inner rect will become bigger than the gui if
    // the user resizes the gui smaller

    for (int i = y0; i < y1; i++) {
        u32* pixel = (u32*) renderState.bufferMemory + x0 + i*renderState.bufferWidth;
        // only colouring the pixels that are needed this is the y axis
        for (int u = x0; u < x1; u++) {
            *pixel++ = color;
            // this is the colour for the x axis
        }
    }
}

template <typename T>
inline T clamp(T min, T val, T max){
    if (val < min) return min;
    if (val > max) return max;
    return val;
    // function used to make the rect smaller if the screen is smaller, basic min max return function
}

void drawArenaBorder(f32 arenaX, f32 arenaY, u32 colour ) {
    arenaX *= static_cast<f32>(renderState.bufferHeight) * renderScale;
    arenaY *= static_cast<f32>(renderState.bufferHeight) * renderScale;

    s32 x0 = (s32)((f32)renderState.bufferWidth * .5f - arenaX);
    s32 x1 = (s32)((f32)renderState.bufferWidth * .5f + arenaX);
    s32 y0 = (s32)((f32)renderState.bufferHeight * .5f - arenaY);
    s32 y1 = (s32)((f32)renderState.bufferHeight * .5f + arenaY);

    draw_rect_in_pixel(0,0, renderState.bufferWidth, y0, colour); // the bottom border
    draw_rect_in_pixel(0,y1, x1, renderState.bufferHeight, colour); // the top border
    draw_rect_in_pixel(0, y0, x0, y1, colour); // the left side border
    draw_rect_in_pixel(x1,y0, renderState.bufferWidth, renderState.bufferHeight, colour); // the right side border

}
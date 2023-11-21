//
// Created by Will&Carm on 11/12/2023.
//

#ifndef UNTITLED_GAMEPLAY_H
#define UNTITLED_GAMEPLAY_H

#include "ButtonsAsteriods.h"
#include "ScreenRender.h"
#include "AsteriodGameScreen.h"
#include <vector>

#define is_down(b) input->buttons[b].isDown
#define pressed(b) (input->buttons[b].isDown && input->buttons[b].change)
//#define is_released(b) (!input->buttons[b].isDown && input->buttons[b].change)

enum GameMode {
    GM_MENU,
    GM_GAMEPLAY
};



class Asteroid {
private:
//    struct aAsteroid {
        f32 y;
        f32 x;
        f32 dx;
        f32 dy;
        s32 size;
//        f32 angle;


public:
    Asteroid(f32 yCord, f32 xCord, f32 xVel, f32 yVel, int i2) : y(yCord), x (xCord), dx(xVel), dy(yVel), size(i2) {}
    Asteroid() : y(), x (), dx(), dy(), size() {}
    void update(f32 dt);
    void draw();

    void wrapCord(float ix, float iy, float &ox, float &oy);

};



void playGame(Input* input, float dt);


#endif //UNTITLED_GAMEPLAY_H

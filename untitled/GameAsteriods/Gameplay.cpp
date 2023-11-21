//
// Created by Will&Carm on 11/12/2023.
//

#include "ButtonsAsteriods.h"
#include "Gameplay .h"
std::vector <Asteroid> vecAsteroid;

f32 player_1_p_x, player_1_p_y, player_1_Dp_x = 10, player_1_dp_y = 10;
f32 arenaHalfSizex = 85, arenaHalfSizeY = 45;
f32 astX= 0, astY = 0, astDpX, astDpY;

GameMode currentGameMode;

void playGame(Input* input, float dt) {

    drawRect(0, 0, arenaHalfSizex, arenaHalfSizeY, BLACK); // the border
    drawArenaBorder(arenaHalfSizex, arenaHalfSizeY, BLUE); // drawing the border
//    if (currentGameMode == GM_GAMEPLAY) {
//
//    f32 player_1_Ddp = 0.f; // units per second
//    if (is_down(BUTTON_Up)) player_1_Ddp += 2000.f;

//    simulatePlayer(&player_1_p_x, &player_1_Dp_x, player_1_Ddp, dt);

player_1_p_x += player_1_Dp_x * dt;
player_1_p_y += player_1_dp_y * dt;

Asteroid a(astX, astY, astDpX = 10, astDpY = -10,10);
vecAsteroid.emplace_back(a);
//a.vecAsteroid.emplace_back(astX, astY, astDpX = 10, astDpY = -10, 10);


    for (Asteroid &hh: vecAsteroid) {
hh.update(dt);
hh.draw();
    }


}

void Asteroid::update(float dt) {
        x += x * dt;
        y += y * dt;

        wrapCord(x, y, x, y);

    }

    void Asteroid::draw() {
        for (s32 i = 0; i < 12; i++) {
            for (s32 j = 0; j < 12; j++) {
                drawRect(i + static_cast<float>(astX), j + static_cast<float>(astY), 0.2, 0.1, WHITE);
            }
        }
    }

    void Asteroid::wrapCord(float ix, float iy, float &ox, float &oy) {
        ox = ix;
        oy = iy;
        if (ix < 0.0f) ox = ix + (float) arenaHalfSizex * 2;
        if (ix >= (float) arenaHalfSizex * 2) ox = ix - (float) arenaHalfSizex * 2;
        if (iy < 0.0f) oy = iy + (float) arenaHalfSizeY * 2;
        if (iy >= (float) arenaHalfSizeY * 2) oy = iy - (float) arenaHalfSizeY * 2;

    }

//void simulatePlayer(f32 *p, f32 *dp, f32 ddp, f32 dt) {
//    ddp -= *dp * 10.f; // this is the friction. higher it is the faster it stops
//
//    *p = *p + *dp * dt + ddp * dt * dt * .5f;
//    *dp = *dp + ddp * dt; // velocity for acceleration
//}


#include <stdio.h>
#include <math.h>
#include <raylib.h>
#include "map.h"
#include "player.h"

int main()
{
    MapInit();
    PlayerInit();
    const int screenWidth = 960;
    const int screenHeight = 540;
    InitWindow(screenWidth, screenHeight, "Raycaster");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        if(IsKeyDown(KEY_W))MoveForward();
        if(IsKeyDown(KEY_S))MoveBackward();
        if(IsKeyDown(KEY_D))MoveRight();
        if(IsKeyDown(KEY_A))MoveLeft();
        if(IsKeyDown(KEY_RIGHT))TurnRight();
        if(IsKeyDown(KEY_LEFT))TurnLeft();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawLittleMap();
        DrawLittlePlayer();
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}

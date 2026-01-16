#include <stdio.h>
#include <math.h>
#include <raylib.h>
#include "map.h"
#include "player.h"
#include "raycaster.h"

int main()
{
    MapInit();
    PlayerInit();
    const int ScreenWidth = 960;
    const int ScreenHeight = 540;
    InitWindow(ScreenWidth, ScreenHeight, "Prisoner of the Garden");
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
        for(int i = 0; i < ScreenWidth; i++)
        {
            RayCast(i, ScreenWidth, ScreenHeight);
        }
        DrawLittleMap();
        DrawLittlePlayer();
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}

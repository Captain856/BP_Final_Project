#include <stdio.h>
#include <math.h>
#include <raylib.h>
#include "map.h"

int main()
{
    MapInit();
    const int screenWidth = 960;
    const int screenHeight = 540;
    InitWindow(screenWidth, screenHeight, "Raycaster");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawMap();
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}

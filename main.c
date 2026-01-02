#include <stdio.h>
#include <math.h>
#include "raylib.h"
#include "map.h"

struct vector{
    float x;
    float y;
};

int main()
{
    MapInit();
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raycaster");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);
    }
    CloseWindow();
    
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <raylib.h>
#include "map.h"
#include "player.h"
#include "raycaster.h"

typedef enum
{
    TUTORIAL,
    MAP,
    EYE
} GameStatus;

int main()
{
    MapInit();
    PlayerInit();
    const int ScreenWidth = 960;
    const int ScreenHeight = 540;
    InitWindow(ScreenWidth, ScreenHeight, "Prisoner of the Garden");
    SetTargetFPS(60);
    GameStatus ViewMode = EYE;
    int timer = 0;
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
        if(ViewMode == EYE)
        {
            for(int i = 0; i < ScreenWidth; i++)
            {
                RayCast(i, ScreenWidth, ScreenHeight);
            }
            DrawLittleMap();
            DrawLittlePlayer();
        }
        if(ViewMode == MAP)
        {
            DrawBigMap();
            DrawBigPlayer();
            if(GetMouseX()>269 && GetMouseX()<691 && GetMouseY()>59 && GetMouseY()<481)
            {
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))ToggleWall(GetMouseX(), GetMouseY());
                if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))ToggleNotWall(GetMouseX(), GetMouseY());
            }
        }
        EndDrawing();
        switch (timer)
        {
            case 0:
                if(IsKeyDown(KEY_M))
                {
                    if(ViewMode == MAP) ViewMode = EYE;
                    else ViewMode = MAP;
                    timer = 1;
                }
                break;
            
            case 15:
                timer = 0;
                break;

            default:
                timer++;
                break;
        }
    }
    CloseWindow();
    
    return 0;
}

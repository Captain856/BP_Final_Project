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

int WelcomePage(int timer);

int main()
{
    MapInit();
    PlayerInit();
    const int ScreenWidth = 960;
    const int ScreenHeight = 540;
    InitWindow(ScreenWidth, ScreenHeight, "Prisoner of the Garden");
    SetTargetFPS(60);
    GameStatus ViewMode = TUTORIAL;
    int timer1 = 0;
    int timer2 = 0;
    while (!WindowShouldClose())
    {
        if(IsKeyDown(KEY_W))MoveForward();
        if(IsKeyDown(KEY_S))MoveBackward();
        if(IsKeyDown(KEY_D))MoveRight();
        if(IsKeyDown(KEY_A))MoveLeft();
        if(IsKeyDown(KEY_RIGHT))TurnRight();
        if(IsKeyDown(KEY_LEFT))TurnLeft();
        BeginDrawing();
        if(ViewMode == TUTORIAL)
        {
            timer2 = WelcomePage(timer2);
            if(timer2>0)if(IsKeyDown(KEY_SPACE))timer2 = -1;
            if(timer2<-60)if(IsKeyDown(KEY_SPACE))ViewMode = EYE;
        }
        if(ViewMode == EYE)
        {
            ClearBackground(RAYWHITE);
            for(int i = 1; i <= ScreenWidth; i++)
            {
                RayCast(i, ScreenWidth, ScreenHeight);
            }
            DrawLittleMap();
            DrawLittlePlayer();
            DrawText("Press 'M' for Map veiw", 733, 245, 19, (Color){0, 0, 0, 150});
            DrawText("Press 'M' for Map veiw", 730, 242, 19, WHITE);
        }
        if(ViewMode == MAP)
        {
            ClearBackground((Color){106, 120, 48, 255});
            DrawBigMap();
            DrawBigPlayer();
            if(GetMouseX()>269 && GetMouseX()<691 && GetMouseY()>59 && GetMouseY()<481)
            {
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))ToggleWall(GetMouseX(), GetMouseY());
                if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))ToggleNotWall(GetMouseX(), GetMouseY());
            }
            DrawText("Press 'M'", 23, 403, 20, (Color){0, 0, 0, 150});
            DrawText("to exit the Map", 23, 428, 20, (Color){0, 0, 0, 150});
            DrawText("mouse left button", 23, 103, 20, (Color){0, 0, 0, 150});
            DrawText("to create a wall", 23, 128, 20, (Color){0, 0, 0, 150});
            DrawText("mouse right button", 23, 178, 20, (Color){0, 0, 0, 150});
            DrawText("to remove a wall", 23, 203, 20, (Color){0, 0, 0, 150});
            DrawText("Press 'M'", 20, 400, 20, WHITE);
            DrawText("to exit the Map", 20, 425, 20, WHITE);
            DrawText("mouse left button", 20, 100, 20, WHITE);
            DrawText("to create a wall", 20, 125, 20, WHITE);
            DrawText("mouse right button", 20, 175, 20, WHITE);
            DrawText("to remove a wall", 20, 200, 20, WHITE);
        }
        EndDrawing();
        switch (timer1)
        {
            case 0:
                if(IsKeyDown(KEY_M))
                {
                    if(ViewMode == MAP) ViewMode = EYE;
                    else ViewMode = MAP;
                    timer1 = 1;
                }
                break;
            
            case 15:
                timer1 = 0;
                break;

            default:
                timer1++;
                break;
        }
    }
    CloseWindow();
    
    return 0;
}

int WelcomePage(int timer)
{
    ClearBackground((Color){106, 120, 48, 255});
    if(timer >= 10 && timer <= 70) DrawText("Loading...", 803, 483, 30, (Color){0, 0, 0, 150});
    if(timer >= 10 && timer <= 70) DrawText("Loading...", 800, 480, 30, WHITE);
    if(timer >= 100) DrawText("PRISONER", 173, 53, 120, (Color){0, 0, 0, 150});
    if(timer >= 100) DrawText("PRISONER", 170, 50, 120, RED);
    if(timer >= 130) DrawText("OF THE", 413, 158, 40, (Color){0, 0, 0, 150});
    if(timer >= 130) DrawText("OF THE", 410, 155, 40, (Color){16, 104, 32, 255});
    if(timer >= 160) DrawText("GARDEN", 303, 193, 90, (Color){0, 0, 0, 150});
    if(timer >= 160) DrawText("GARDEN", 300, 190, 90, (Color){16, 104, 32, 255});
    if(timer >= 210) DrawText("press 'Space' to continue", 293, 403, 30, (Color){0, 0, 0, 150});
    if(timer >= 210) DrawText("press 'Space' to continue", 290, 400, 30, WHITE);
    if(timer < 0)
    {
        DrawText("'TUTORIAL'", 53, 53, 40, (Color){0, 0, 0, 150});
        DrawText("'TUTORIAL'", 50, 50, 40, WHITE);
        DrawText("use 'W', 'A', 'S' and 'D' to move in the Garden", 73, 133, 30, (Color){0, 0, 0, 150});
        DrawText("use 'W', 'A', 'S' and 'D' to move in the Garden", 70, 130, 30, WHITE);
        DrawText("use '<-' and '->' to turn around", 73, 173, 30, (Color){0, 0, 0, 150});
        DrawText("use '<-' and '->' to turn around", 70, 170, 30, WHITE);
        DrawText("when ready, press 'Space'", 73, 453, 30, (Color){0, 0, 0, 150});
        DrawText("when ready, press 'Space'", 70, 450, 30, WHITE);
        return timer-1;
    }
    return timer+1;
}
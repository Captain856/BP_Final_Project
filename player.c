#include "player.h"
#include "map.h"
#include <raylib.h>
#include <math.h>

vector1 pos;
vector1 dir;
vector2 plane;
float bigradius;
float littleradius;
float Speed;

void PlayerInit(void)
{
    pos.x = 9.5;
    pos.y = 5.5;
    dir.x = 0.0;
    dir.y = 1.0;
    bigradius = 10;
    littleradius = 6;
}

void DrawBigPlayer(void)
{
    DrawCircle(pos.x*Big_Tile_Size+240, pos.y*Big_Tile_Size+30, bigradius, RED);
    DrawLine(pos.x*Big_Tile_Size+240, pos.y*Big_Tile_Size+30, pos.x*Big_Tile_Size+dir.x*Big_Tile_Size+240, pos.y*Big_Tile_Size-dir.y*Big_Tile_Size+30, RED);
}

void DrawLittlePlayer(void)
{
    DrawCircle(pos.x*Little_Tile_Size+720, pos.y*Little_Tile_Size+16, littleradius, RED);
    DrawLine(pos.x*Little_Tile_Size+720, pos.y*Little_Tile_Size+16, pos.x*Little_Tile_Size+dir.x*Little_Tile_Size+720, pos.y*Little_Tile_Size-dir.y*Little_Tile_Size+16, RED);
}

void MoveForward(void)
{
    Speed = 6;
    float dt = GetFrameTime();
    if(!IsWall(pos.x + Speed * dt * dir.x, pos.y))pos.x += Speed * dt * dir.x;
    if(!IsWall(pos.x, pos.y - Speed * dt * dir.y))pos.y -= Speed * dt * dir.y;
}

void MoveBackward(void)
{
    Speed = 6;
    float dt = GetFrameTime();
    if(!IsWall(pos.x - Speed * dt * dir.x, pos.y))pos.x -= Speed * dt * dir.x;
    if(!IsWall(pos.x, pos.y + Speed * dt * dir.y))pos.y += Speed * dt * dir.y;
}

void MoveRight(void)
{
    Speed = 6;
    float dt = GetFrameTime();
    if(!IsWall(pos.x + Speed * dt * dir.y, pos.y))pos.x += Speed * dt * dir.y;
    if(!IsWall(pos.x, pos.y + Speed * dt * dir.x))pos.y += Speed * dt * dir.x;
}

void MoveLeft(void)
{
    Speed = 6;
    float dt = GetFrameTime();
    if(!IsWall(pos.x - Speed * dt * dir.y, pos.y))pos.x -= Speed * dt * dir.y;
    if(!IsWall(pos.x, pos.y - Speed * dt * dir.x))pos.y -= Speed * dt * dir.x;
}

void TurnRight(void)
{
    Speed = -4;
    float dt = GetFrameTime();
    float hold = dir.x;
    dir.x = dir.x * cos(Speed * dt) - dir.y * sin(Speed * dt);
    dir.y = hold * sin(Speed * dt) + dir.y * cos(Speed * dt);
}

void TurnLeft(void)
{
    Speed = 4;
    float dt = GetFrameTime();
    float hold = dir.x;
    dir.x = dir.x * cos(Speed * dt) - dir.y * sin(Speed * dt);
    dir.y = hold * sin(Speed * dt) + dir.y * cos(Speed * dt);
}
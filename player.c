#include "player.h"
#include "map.h"
#include <raylib.h>
#include <math.h>

vector1 pos;
vector1 dir;
vector2 plane;
float radius;
float Speed;

void PlayerInit(void)
{
    pos.x = 9.5*Tile_Size;
    pos.y = 5.5*Tile_Size;
    dir.x = 0.0*Tile_Size;
    dir.y = 1.0*Tile_Size;
    radius = 10;
}

void DrawPlayer(void)
{
    DrawCircle(pos.x+240, pos.y+30, radius, RED);
    DrawLine(pos.x+240, pos.y+30, pos.x+dir.x+240, pos.y-dir.y+30, RED);
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
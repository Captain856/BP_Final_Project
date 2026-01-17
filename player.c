#include "player.h"
#include "map.h"
#include <raylib.h>
#include <math.h>

Player player;

void PlayerInit(void)
{
    player.pos.x = 9.5;
    player.pos.y = 5.5;
    player.dir.x = 0.0;
    player.dir.y = 1.0;
    player.plane.x = 0.66;
    player.plane.y = 0.00;
    return;
}

void DrawBigPlayer(void)
{
    DrawCircle(player.pos.x*Big_Tile_Size+240, player.pos.y*Big_Tile_Size+30, Big_Radius, RED);
    DrawLine(player.pos.x*Big_Tile_Size+240, player.pos.y*Big_Tile_Size+30, player.pos.x*Big_Tile_Size+player.dir.x*Big_Tile_Size+240, player.pos.y*Big_Tile_Size-player.dir.y*Big_Tile_Size+30, RED);
    return;
}

void DrawLittlePlayer(void)
{
    DrawCircle(player.pos.x*Little_Tile_Size+720, player.pos.y*Little_Tile_Size+16, Little_Radius, RED);
    DrawLine(player.pos.x*Little_Tile_Size+720, player.pos.y*Little_Tile_Size+16, player.pos.x*Little_Tile_Size+player.dir.x*Little_Tile_Size+720, player.pos.y*Little_Tile_Size-player.dir.y*Little_Tile_Size+16, RED);
    //plane test
    DrawLine(player.pos.x*Little_Tile_Size+player.dir.x*Little_Tile_Size+720, player.pos.y*Little_Tile_Size-player.dir.y*Little_Tile_Size+16, player.pos.x*Little_Tile_Size+player.dir.x*Little_Tile_Size+player.plane.x*Little_Tile_Size+720, player.pos.y*Little_Tile_Size-player.dir.y*Little_Tile_Size-player.plane.y*Little_Tile_Size+16, GREEN);
    return;
}

void MoveForward(void)
{
    float dt = GetFrameTime();
    if(!IsWall(player.pos.x + Speed * dt * player.dir.x, player.pos.y))player.pos.x += Speed * dt * player.dir.x;
    if(!IsWall(player.pos.x, player.pos.y - Speed * dt * player.dir.y))player.pos.y -= Speed * dt * player.dir.y;
    return;
}

void MoveBackward(void)
{
    float dt = GetFrameTime();
    if(!IsWall(player.pos.x - Speed * dt * player.dir.x, player.pos.y))player.pos.x -= Speed * dt * player.dir.x;
    if(!IsWall(player.pos.x, player.pos.y + Speed * dt * player.dir.y))player.pos.y += Speed * dt * player.dir.y;
    return;
}

void MoveRight(void)
{
    float dt = GetFrameTime();
    if(!IsWall(player.pos.x + Speed * dt * player.dir.y, player.pos.y))player.pos.x += Speed * dt * player.dir.y;
    if(!IsWall(player.pos.x, player.pos.y + Speed * dt * player.dir.x))player.pos.y += Speed * dt * player.dir.x;
    return;
}

void MoveLeft(void)
{
    float dt = GetFrameTime();
    if(!IsWall(player.pos.x - Speed * dt * player.dir.y, player.pos.y))player.pos.x -= Speed * dt * player.dir.y;
    if(!IsWall(player.pos.x, player.pos.y - Speed * dt * player.dir.x))player.pos.y -= Speed * dt * player.dir.x;
    return;
}

void TurnRight(void)
{
    float dt = GetFrameTime();
    float hold1 = player.dir.x;
    player.dir.x = player.dir.x * cos(-TurnSpeed * dt) - player.dir.y * sin(-TurnSpeed * dt);
    player.dir.y = hold1 * sin(-TurnSpeed * dt) + player.dir.y * cos(-TurnSpeed * dt);
    float hold2 = player.plane.x;
    player.plane.x = player.plane.x * cos(-TurnSpeed * dt) - player.plane.y * sin(-TurnSpeed * dt);
    player.plane.y = hold2 * sin(-TurnSpeed * dt) + player.plane.y * cos(-TurnSpeed * dt);
    return;
}

void TurnLeft(void)
{
    float dt = GetFrameTime();
    float hold1 = player.dir.x;
    player.dir.x = player.dir.x * cos(TurnSpeed * dt) - player.dir.y * sin(TurnSpeed * dt);
    player.dir.y = hold1 * sin(TurnSpeed * dt) + player.dir.y * cos(TurnSpeed * dt);
    float hold2 = player.plane.x;
    player.plane.x = player.plane.x * cos(TurnSpeed * dt) - player.plane.y * sin(TurnSpeed * dt);
    player.plane.y = hold2 * sin(TurnSpeed * dt) + player.plane.y * cos(TurnSpeed * dt);
    return;
}

Player GetPlayer(void)
{
    return player;
}
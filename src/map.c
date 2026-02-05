#include "map.h"
#include "player.h"
#include <raylib.h>
#include <math.h>

int World_Map[16][16];

//first initialization
void MapInit(void)
{
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            World_Map[i][j] = 0;
        }
    }
    for(int i = 0; i < 16; i++){
        World_Map[0][i] = 1;
        World_Map[i][0] = 1;
        World_Map[15][i] = 1;
        World_Map[i][15] = 1;
    }
    World_Map[1][7] = 1;
    World_Map[2][7] = 1;
    World_Map[3][7] = 1;
    World_Map[4][7] = 1;
    World_Map[4][11] = 1;
    World_Map[5][1] = 1;
    World_Map[5][2] = 1;
    World_Map[5][3] = 1;
    World_Map[5][7] = 1;
    World_Map[5][11] = 1;
    World_Map[6][3] = 1;
    World_Map[6][7] = 1;
    World_Map[6][11] = 1;
    World_Map[7][3] = 1;
    World_Map[7][7] = 1;
    World_Map[7][8] = 1;
    World_Map[7][9] = 1;
    World_Map[7][10] = 1;
    World_Map[7][11] = 1;
    World_Map[8][3] = 1;
    World_Map[11][1] = 1;
    World_Map[11][2] = 1;
    World_Map[11][3] = 1;
    World_Map[11][4] = 1;
    World_Map[11][5] = 1;
    World_Map[11][6] = 1;
    World_Map[11][7] = 1;
    World_Map[11][8] = 1;
    World_Map[11][9] = 1;
    World_Map[11][13] = 1;
    World_Map[11][14] = 1;
    return;
}

//Drawing the Big map
void DrawBigMap(void)
{
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            if(World_Map[i][j]==1){
                DrawRectangle(j*Big_Tile_Size+240, i*Big_Tile_Size+30, Big_Tile_Size, Big_Tile_Size, GRAY);
                DrawRectangleLines(j*Big_Tile_Size+240, i*Big_Tile_Size+30, Big_Tile_Size, Big_Tile_Size, BLACK);
            }
            else{
                DrawRectangle(j*Big_Tile_Size+240, i*Big_Tile_Size+30, Big_Tile_Size, Big_Tile_Size, WHITE);
                DrawRectangleLines(j*Big_Tile_Size+240, i*Big_Tile_Size+30, Big_Tile_Size, Big_Tile_Size, BLACK);
            }
        }
    }
    return;
}

//Drawing the Little map
void DrawLittleMap(void)
{
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            if(World_Map[i][j]==1){
                DrawRectangle(j*Little_Tile_Size+720, i*Little_Tile_Size+16, Little_Tile_Size, Little_Tile_Size, GRAY);
                DrawRectangleLines(j*Little_Tile_Size+720, i*Little_Tile_Size+16, Little_Tile_Size, Little_Tile_Size, BLACK);
            }
            else{
                DrawRectangle(j*Little_Tile_Size+720, i*Little_Tile_Size+16, Little_Tile_Size, Little_Tile_Size, WHITE);
                DrawRectangleLines(j*Little_Tile_Size+720, i*Little_Tile_Size+16, Little_Tile_Size, Little_Tile_Size, BLACK);
            }
        }
    }
    return;
}

//is this wall?
int IsWall(float x, float y)
{
    return World_Map[(int)(floor(y))][(int)(floor(x))];
}

//toggle a not wall to a wall
void ToggleWall(int X, int Y)
{
    Player player = GetPlayer();
    X = (X - 240)/Big_Tile_Size;
    Y = (Y - 30)/Big_Tile_Size;
    if((int)(player.pos.x) == X && (int)(player.pos.y) == Y)return;
    if(World_Map[Y][X]==0) World_Map[Y][X] = 1;
    return;
}

//toggle a wall to a not wall
void ToggleNotWall(int X, int Y)
{
    X = (X - 240)/Big_Tile_Size;
    Y = (Y - 30)/Big_Tile_Size;
    if(World_Map[Y][X]==1) World_Map[Y][X] = 0;
    return;
}
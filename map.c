#include "map.h"
#include <raylib.h>

int World_Map[16][16];
const int Tile_Size = 30;

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
}

//Drawing the map
void DrawMap()
{
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            if(World_Map[i][j]==1){
                DrawRectangle(j*Tile_Size, i*Tile_Size, Tile_Size, Tile_Size, GRAY);
                DrawRectangleLines(j*Tile_Size, i*Tile_Size, Tile_Size, Tile_Size, BLACK);
            }
            else{
                DrawRectangle(j*Tile_Size, i*Tile_Size, Tile_Size, Tile_Size, WHITE);
                DrawRectangleLines(j*Tile_Size, i*Tile_Size, Tile_Size, Tile_Size, BLACK);
            }
        }
    }
}
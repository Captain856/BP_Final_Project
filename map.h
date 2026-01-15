#ifndef MAP_H
#define MAP_H

#define Big_Tile_Size 30
#define Little_Tile_Size 14

void MapInit(void);
void DrawBigMap(void);
void DrawLittleMap(void);
int IsWall(float x, float y);

#endif
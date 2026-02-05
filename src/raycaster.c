#include <math.h>
#include <raylib.h>
#include "raycaster.h"
#include "player.h"
#include "map.h"

void DrawRayCast(int WallStart, int WallEnd, int WidthX, int Height, int side)
{
    Color MyBrown = (Color){181, 142, 75, 255};
    Color MyDarkBrown = (Color){152, 120, 64, 255};
    Color MySky = (Color){23, 198, 236, 255};
    Color MyFloor = (Color){69, 88, 45, 255};
    Color WallColor = MyBrown;
    if(side)WallColor = MyDarkBrown;
    DrawLine(WidthX, 0, WidthX, WallStart, MySky);
    DrawLine(WidthX, WallStart, WidthX, WallEnd, WallColor);
    DrawLine(WidthX, WallEnd, WidthX, Height, MyFloor);
    return;
}

void RayCast(int WidthX, int Width, int Height)
{
    int WallStart;
    int WallEnd;
    double LineHeight;
    double WallDist;
    double CameraX = ( (double)WidthX )/( (double)Width/2 ) - 1;
    vector RayDir;
    Player player = GetPlayer();
    RayDir.x = player.dir.x + (player.plane.x * CameraX);
    RayDir.y = -player.dir.y - (player.plane.y * CameraX);

    vector DeltaDist;
    DeltaDist.x = (RayDir.x == 0) ? 1e30 : fabs(1 / RayDir.x);
    DeltaDist.y = (RayDir.y == 0) ? 1e30 : fabs(1 / RayDir.y);

    vector Step;
    vector SideDist;
    int MapX = floor(player.pos.x);
    int MapY = floor(player.pos.y);

    if(RayDir.x < 0)
    {
        Step.x = -1;
        SideDist.x = (player.pos.x - MapX) * DeltaDist.x;
    }
    else
    {
        Step.x = 1;
        SideDist.x = (MapX + 1.0 - player.pos.x) * DeltaDist.x;
    }

    if(RayDir.y < 0)
    {
        Step.y = -1;
        SideDist.y = (player.pos.y - MapY) * DeltaDist.y;
    }
    else
    {
        Step.y = 1;
        SideDist.y = (MapY + 1.0 - player.pos.y) * DeltaDist.y;
    }

    int hit = 0;
    int side = 0;
    while(hit == 0)
    {
        if(SideDist.x < SideDist.y)
        {
            SideDist.x += DeltaDist.x;
            MapX += Step.x;
            side = 0;
        }
        else
        {
            SideDist.y += DeltaDist.y;
            MapY += Step.y;
            side = 1;
        }
        if(IsWall(MapX, MapY)) hit = 1;
    }

    if(side) WallDist = SideDist.y-DeltaDist.y;
    else WallDist = SideDist.x-DeltaDist.x;
    LineHeight = Height/WallDist;
    WallStart = Height/2 - LineHeight/2;
    WallEnd = Height/2 + LineHeight/2;
    DrawRayCast(WallStart, WallEnd, WidthX, Height, side);
    return;
}
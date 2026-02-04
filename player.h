#ifndef PLAYER_H
#define PLAYER_H

#define Big_Radius 10
#define Little_Radius 6
#define TurnSpeed 4

struct vector{
    double x;
    double y;
};
typedef struct vector vector;

struct Player{
    vector pos;
    vector dir;
    vector plane;
};
typedef struct Player Player;

void PlayerInit(void);
void DrawBigPlayer(void);
void DrawLittlePlayer(void);
void MoveForward(void);
void MoveBackward(void);
void MoveRight(void);
void MoveLeft(void);
void TurnRight(void);
void TurnLeft(void);
Player GetPlayer(void);

#endif
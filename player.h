#ifndef PLAYER_H
#define PLAYER_H

struct vector1{
    float x;
    float y;
};
typedef struct vector1 vector1;

struct vector2{
    float r;
    float h;
};
typedef struct vector2 vector2;

void PlayerInit(void);
void DrawPlayer(void);
void MoveForward(void);
void MoveBackward(void);
void MoveRight(void);
void MoveLeft(void);
void TurnRight(void);
void TurnLeft(void);

#endif
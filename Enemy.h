#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

class Enemy
{
    private:
    Vector2 position;
    Vector2 size;
    float speed;
    Color color;
    float direction;

    public:
    Enemy(Vector2 pos, Vector2 sz, float s, Color c, float d);
    //Enemy();

    void Draw();

    void Update();

    bool CheckCollision(Vector2 ballPosition, float ballRadius);

    bool IsOutOfScreen();

    float GetYPosition();

    Color SetColor();

    float SetSpeed();
};

#endif
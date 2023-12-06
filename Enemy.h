#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

class Enemy
{
    private:
    Vector2 position;
    Vector2 size;
    Color color;
    float speed;

    public:
    Enemy(Vector2 pos, Vector2 sz, Color c, float s);
    //Enemy();

    void Draw();

    void Update(float dir);

    bool CheckCollision(Vector2 ballPosition, float ballRadius);

    bool IsOutOfScreen();

    float GetYPosition();
};

#endif
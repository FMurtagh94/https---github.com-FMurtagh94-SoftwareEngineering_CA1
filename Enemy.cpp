#include "Enemy.h"


Enemy::Enemy(Vector2 pos, Vector2 sz, Color c, float s)
: position(pos),
    size(sz),
    color(c),
    speed(s){}

Enemy::Enemy(): position ({0,0}),size({0,0}), color(BLANK), speed(0.0f) {}

void Enemy::Draw()
{
    DrawRectangleV(position, size, color);
}

void Enemy::Update()
{
    position.y += speed;
    
}

bool Enemy::CheckCollision(Vector2 ballPosition, float ballRadius)
{
    Rectangle obstacleRect = {position.x, position.y, size.x, size.y};
    return CheckCollisionCircleRec(ballPosition, ballRadius, obstacleRect);
}

bool Enemy::IsOutOfScreen()
{
    return position.y > (GetScreenHeight()/2)+50;
}
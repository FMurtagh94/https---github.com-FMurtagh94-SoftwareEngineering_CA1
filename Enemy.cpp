#include "Enemy.h"


Enemy::Enemy(Vector2 pos, Vector2 sz, Color c, float s, float d)
: position(pos),
    size(sz),
    color(c),
    speed(s),
    direction(d){}

//Enemy::Enemy(): position ({0,0}),size({0,0}), color(BLANK), speed(0.0f) {}

void Enemy::Draw()
{
    DrawRectangleV(position, size, color);
}

void Enemy::Update()
{
    if(position.y <= 45 || position.y >= 425) //Setting perimeter of the enemy
    {
        speed *= -1.0f;
    }
    position.y += speed;
}

bool Enemy::CheckCollision(Vector2 playerPosition, float playerRadius)
{
    Rectangle obstacleRect = {position.x, position.y, size.x, size.y};
    return CheckCollisionCircleRec(playerPosition, playerRadius, obstacleRect);
}

bool Enemy::IsOutOfScreen()
{
    return position.y > (GetScreenHeight()/2)+50;
}

float Enemy::GetYPosition()
{
    return position.y;
}
#include "Enemy.h"


Enemy::Enemy(Vector2 pos, Vector2 sz, float s, Color c, float d)
: position(pos),
    size(sz),
    speed(s),
    color(c),
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

Color Enemy::SetColor() //Set Color Based on Speed
{
    if(speed >= 5.0f && speed < 7.0f)
    {
        color = WHITE;
    }
    else if(speed >= 7.0f && speed < 9.0f)
    {
        color = GREEN;
    }
    else if(speed >= 9.0f && speed < 11.0f)
    {
        color = PURPLE;
    }
    else
    {
        color = BLUE;
    }

    return color;
}

float Enemy::SetSpeed() //Randomly Set Speed
{
   int a = GetRandomValue(0, 3);
   if(a == 0)
    {
        speed = 5.0f;
    }
    else if(a == 1)
    {
        speed = 7.0f;
    }
    else if(a == 2)
    {
        speed = 9.0f;
    }
    else
    {
        speed = 11.0f;
    }
    
    return speed;
}
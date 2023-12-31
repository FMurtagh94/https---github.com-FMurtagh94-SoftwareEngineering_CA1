#include "Enemy.h"


Enemy::Enemy(Vector2 pos, Vector2 sz, float s, Color c)
: position(pos),
    size(sz),
    speed(s),
    color(c){}

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


Color Enemy::SetColor(float nSpeed) //Set Color Based on Speed
{
    int h = (int)nSpeed;
    if(h == 5)
    {
        color = WHITE;
    }
    else if(h == 7)
    {
        color = GREEN;
    }
    else if(h == 9)
    {
        color = PURPLE;
    }
    else
    {
        color = BLUE;
    }

    return color;
}

/*float Enemy::SetSpeed() //Randomly Set Speed
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
}*/
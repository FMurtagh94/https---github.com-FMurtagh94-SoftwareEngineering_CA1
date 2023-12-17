#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(Vector2 pos, float r, Color c)
:   
    position(pos),
    radius(r),
    color(c){}

void Player::Draw()
{
    DrawCircleV(position,radius,color);
}

void Player::Move(Vector2 offset)
{
    position.x += offset.x;
    position.y += offset.y;
}

Vector2 Player::GetPosition() const
{
    return position;
}

float Player::GetRadius() const
{
    return radius;
}

void Player::Reset()
{
    position.x = 30;
}

Color Player::ChangeColour(int lives)
{
    if(lives >= 3)
    {
        color = GREEN;
    }
    else if(lives == 2)
    {
        color = YELLOW;
    }
    else if(lives <= 1)
    {
        color = RED;
    }
    return color;
}


bool Player::Finish(int finishLineX)
{
    if(position.x >= finishLineX)
    {
        return true;
    }
    else
    {
        return false;
    }
}
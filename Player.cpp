#include "Player.h"
#include <iostream>
using namespace std;

//Player::Player(Texture2D text, Rectangle sourceRec, Vector2 pos, float r, Color c)
Player::Player(Vector2 pos, float r, Color c)
:   
    //texture(text),
    //sourceRec(sourceRec),
    position(pos),
    radius(r),
    color(c){}

void Player::Draw()
{
    DrawCircleV(position,radius,color);
    //DrawTextureRec(texture, sourceRec, position, WHITE);
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
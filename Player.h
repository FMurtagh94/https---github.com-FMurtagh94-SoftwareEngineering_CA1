#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player
{
    private:
    //Texture2D texture;
    //Rectangle sourceRec;
    Vector2 position;
    float radius;
    Color color;

    public:
    //Player(Texture2D text, Rectangle sourceRec, Vector2 pos, float r, Color c);
    Player(Vector2 pos, float r, Color c);

    void Draw();

    void Move(Vector2 offset);

    Vector2 GetPosition() const;

    float GetRadius() const;

    void Reset();

    Color ChangeColour(int lives); 
};

#endif
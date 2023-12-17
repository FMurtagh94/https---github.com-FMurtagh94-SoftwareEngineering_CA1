#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player
{
    private:
    Vector2 position;
    float radius;
    Color color;

    public:

    Player(Vector2 pos, float r, Color c);
    void Draw();

    void Move(Vector2 offset);

    Vector2 GetPosition() const;

    float GetRadius() const;

    void Reset();

    Color ChangeColour(int lives);

    bool Finish(int finishLineX);
};

#endif
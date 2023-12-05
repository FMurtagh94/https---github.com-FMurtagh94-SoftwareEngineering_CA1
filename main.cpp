#include "raylib.h"
#include "Player.h"
//#include "Obstacle.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

const int MAX_OBSTACLES = 10;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Fiachra_Murtagh_Game");

    Player player({screenWidth/2, screenHeight-50}, 20, RAYWHITE); //Player

    Enemy enemy[MAX_OBSTACLES]; //Test Enemy

    for(int i = 0; i<MAX_OBSTACLES; ++i)
    {
        float width = GetRandomValue(50,200);
        enemy[i] = Enemy({(float)GetRandomValue(0,screenWidth-(int)width), (float)(-20.0f-i*60)}, {width, 20.f}, RED, 4.0f);
    }
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int score = 0;
    bool gameOver = false; 

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(!gameOver)
        {
            if(IsKeyDown(KEY_RIGHT)&& player.GetPosition().x< screenWidth - player.GetRadius())
            player.Move({5,0});

            if(IsKeyDown(KEY_LEFT)&& player.GetPosition().x< screenWidth - player.GetRadius())
            player.Move({-5,0});
        }
        for(int i= 0; i< MAX_OBSTACLES; ++i)
        {
           if(enemy[i].IsOutOfScreen())
           {
                float width = GetRandomValue(50,200);
                enemy[i] = Enemy({(float)GetRandomValue(0,screenWidth - (int)width), -20.0f},
                {width, 20.0f}, RED, 4.0f);
            }
            enemy[i].Update();

            if(enemy[5].CheckCollision(player.GetPosition(), player.GetRadius()))
            {
                gameOver = true;
            }
            score++;
        }

        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            player.Draw();
            for(int i = 0; i<MAX_OBSTACLES; ++i)
            {
                enemy[5].Draw();
            }

            DrawText(TextFormat("Score: %i", score), 10,10,20, RAYWHITE);

            if(gameOver)
            {
                DrawText("GAME OVER", screenWidth/2 -60, screenHeight/2,20, RED);
            }



        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

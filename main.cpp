#include "raylib.h"
#include "Player.h"
//#include "Obstacle.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

const int MAX_OBSTACLES = 5;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1800;
    int screenHeight = 800;
    int score = 0;
    bool gameOver = false; 
    bool enemyDir;
    int changeDir;
    /*
    //Set Texture for Player
    Texture2D playerTexture = LoadTexture("Resources/Textures/scarfy.png");
    //Setting Player Textyre Height
    Rectangle sourceRec = (Rectangle){0.0f, 0.0f, (float)(playerTexture.width)/6, (float)(playerTexture.height)};
    */
    
    InitWindow(screenWidth, screenHeight, "Fiachra_Murtagh_Game");

    //Player player(playerTexture, sourceRec, {screenWidth/2, screenHeight-50}, 20, RAYWHITE); //Player
    Player player({30, (screenHeight/2)+50}, 20, RAYWHITE); //Player
    //player.texture = LoadTexture("Resources/Textures/scarfy.png");
    //Enemy enemy[MAX_OBSTACLES]; //Test Enemy
    Enemy enemy1({(float)200, 50}, {50.0f, 50.0f}, WHITE, 5.0f); //Enemy

    
    
    /* Temp Blocking Enemy Code*/
    /*
    for(int i = 0; i<MAX_OBSTACLES; ++i)
    {
        float width = GetRandomValue(50,200);
        enemy[i] = Enemy({(float)GetRandomValue(0,screenWidth-(int)width), (float)(-20.0f-i*60)}, {width, 20.f}, GREEN, 4.0f);
    }
    */
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(!gameOver)
        {
            if(IsKeyDown(KEY_RIGHT)&& player.GetPosition().x< screenWidth - player.GetRadius())
            player.Move({5,0});

            if(IsKeyDown(KEY_LEFT)&& player.GetPosition().x<= screenWidth - player.GetRadius())
            player.Move({-5,0});
        }
        /*Enemy Stuff*/
        /*
        for(int i= 0; i< MAX_OBSTACLES; ++i)
        {
           /*if(enemy[i].IsOutOfScreen())
           {
                float width = GetRandomValue(50,200);
                enemy[i] = Enemy({(float)GetRandomValue(0,screenWidth - (int)width), -20.0f},
                {width, 20.0f}, RED, 4.0f);
           } //End to be blocked
           if(enemy[i].IsOutOfScreen())
           {
            enemy[i] = Enemy({(float)(screenWidth - 50), -20.0f},
                {50, 20.0f}, RED, 4.0f);
           }

            enemy[i].Update();

            if(enemy[i].CheckCollision(player.GetPosition(), player.GetRadius()))
            {
                gameOver = true;
            }
            if(!gameOver)
            {
                score++;
            }
        }*/
        
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLUE);
            player.Draw();
            
            /*for(int i = 0; i<MAX_OBSTACLES; ++i)
            {
                enemy[i].Draw();
            }*/
            //Ground
            DrawRectangle(0, (((screenHeight/2)+50)+player.GetRadius()), screenWidth, (screenHeight/2)+50, RED);
            DrawText(TextFormat("Score: %i", score), 10,10,20, RAYWHITE);
            enemy1.Draw();
            if(gameOver)
            {
                DrawText("GAME OVER", screenWidth/2 -60, screenHeight/2,20, RED);
            }


            //Trying to get the enemy to change direction
            if(enemy1.GetYPosition() == 50)
            {
                enemyDir = true;
            }
            else if(enemy1.GetYPosition() == 300)
            {
                enemyDir = false;
            }

            if(enemyDir)
            {
                changeDir = 1;
            }
            else
            {
                changeDir = -1;
            }

            enemy1.Update(changeDir);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

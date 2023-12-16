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
    //Texture2D background = LoadTexture("Resources/Textures/cyberpunk_street_background.png");
    int screenWidth = 1800;
    int screenHeight = 800;
    int score = 0;
    int lives = 3;
    bool gameOver = false; 
    bool enemyDir = false;
    float changeDir;
    bool getDir;
    float getY; 
    /*
    //Set Texture for Player
    Texture2D playerTexture = LoadTexture("Resources/Textures/scarfy.png");
    //Setting Player Textyre Height
    Rectangle sourceRec = (Rectangle){0.0f, 0.0f, (float)(playerTexture.width)/6, (float)(playerTexture.height)};
    */
    
    InitWindow(screenWidth, screenHeight, "Fiachra_Murtagh_Game");
    Texture2D background = LoadTexture("Resources/Textures/cyberpunk_street_background.png");
    background.width = background.width*4;
    background.height = background.height*3;
    //Player player(playerTexture, sourceRec, {screenWidth/2, screenHeight-50}, 20, RAYWHITE); //Player
    Player player({30, (screenHeight/2)+50}, 20, RAYWHITE); //Player
    //player.texture = LoadTexture("Resources/Textures/scarfy.png");
    //Enemy enemy[MAX_OBSTACLES]; //Test Enemy
    Enemy enemy1({(float)150, 50}, {50.0f, 50.0f}, WHITE, 5.0f, 0); //Enemy
    Enemy enemy2({(float)300, 50}, {50.0f, 50.0f}, GREEN, 7.0f, 0);
    Enemy enemy3({(float)350, 50}, {50.0f, 50.0f}, PURPLE, 9.0f, 0);

    Enemy enemy4({(float)450, 50}, {50.0f, 50.0f}, WHITE, 5.0f, 0);
    Enemy enemy5({(float)500, 100}, {50.0f, 50.0f}, WHITE, 7.0f, 0);
    Enemy enemy6({(float)550, 150}, {50.0f, 50.0f}, WHITE, 9.0f, 0);
    Enemy enemy7({(float)600, 100}, {50.0f, 50.0f}, WHITE, 11.0f, 0);
    Enemy enemy8({(float)650, 50}, {50.0f, 50.0f}, WHITE, 13.0f, 0);
    
    
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

            enemy[i].Update();*/

            if(enemy1.CheckCollision(player.GetPosition(), player.GetRadius())
            || enemy2.CheckCollision(player.GetPosition(), player.GetRadius())
            || enemy3.CheckCollision(player.GetPosition(), player.GetRadius()))
            {
                lives = lives - 1;
                if(lives <= 0)
                {
                    gameOver = true;
                }
                player.Reset(); //When player dies, this resets them to the beginning
            }
            if(!gameOver)
            {
                score++;
            }
        
    
        
        
        // Update
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLUE);
            DrawTexture(background, 0, 0, WHITE);
            //ClearBackground(WHITE); 

			//DrawTexture(background, 0, 0, WHITE);
            //DrawTextureEx(background, (Vector2){ background.width*2 + 0, 20 }, 0.0f, 2.0f, WHITE);
            
            
            
            player.Draw();
            
            /*for(int i = 0; i<MAX_OBSTACLES; ++i)
            {
                enemy[i].Draw();
            }*/
            //Ground
            DrawRectangle(0, (((screenHeight/2)+50)+player.GetRadius()), screenWidth, (screenHeight/2)+50, RED);
            DrawText(TextFormat("Lives: %i", lives), 10,10,50, RED);
            enemy1.Draw();
            enemy2.Draw();
            enemy3.Draw();

            enemy4.Draw();
            enemy5.Draw();
            enemy6.Draw();
            enemy7.Draw();
            enemy8.Draw();
            if(gameOver)
            {
                DrawText("GAME OVER", screenWidth/2 -550, screenHeight/2,200, BLACK);
            }


            //Trying to get the enemy to change direction
            /*if(enemy1.GetYPosition() <= 50) //Check & change Enemy Y Position
            {
                changeDir = 1;
            }
            if(enemy1.GetYPosition() >= 300)
            {
                changeDir = -1;
            }*/

            //enemy1.GetYPosition();
            if(!gameOver)
            {
                enemy1.Update();
                enemy2.Update();
                enemy3.Update();

                enemy4.Update();
                enemy5.Update();
                enemy6.Update();
                enemy7.Update();
                enemy8.Update();
            }

            /*if(enemyDir == true) //Change the direction dependng on Y position
            {
                changeDir = 1;
            }
            else if(enemyDir == false)
            {
                changeDir = -1;
            }*/

            


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

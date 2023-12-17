#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

//Student: Fiachra Murtagh, D00155450

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1800;
    int screenHeight = 800;
    int lives = 3;
    bool gameOver = false;
    bool wonGame = false;
    int finishLineX = screenWidth - 300;
    /*
    //Set Texture for Player
    Texture2D playerTexture = LoadTexture("Resources/Textures/scarfy.png");
    //Setting Player Textyre Height
    Rectangle sourceRec = (Rectangle){0.0f, 0.0f, (float)(playerTexture.width)/6, (float)(playerTexture.height)};
    */
    
    InitWindow(screenWidth, screenHeight, "Fiachra_Murtagh_Game");

    //Setting Textures
    Texture2D background = LoadTexture("Resources/Textures/cyberpunk_street_background.png");
    background.width = background.width*(screenWidth/background.width)+400;
    background.height = background.height*3;

    Texture2D finishLine = LoadTexture("Resources/Textures/finishLine.png");

    Texture2D winnerScreen = LoadTexture("Resources/Textures/winnerScreen.png");
    winnerScreen.height=screenHeight;
    winnerScreen.width=screenWidth;

    Texture2D gameOverScr = LoadTexture("Resources/Textures/gameOver.png");
    gameOverScr.height=screenHeight;
    gameOverScr.width=screenWidth;

    InitAudioDevice();
    Sound sound = LoadSound("Resources/Sounds/sound.wav");

    //Texture2D playerT = LoadTexture("Resources/Textures/scarfy.png");

    int volume = 50;
    SetSoundVolume(sound, volume/100.0f);

    //Setting Player Details
    Player player({30, (screenHeight/2)+50}, 20, player.ChangeColour(lives));

    //Setting Enemy Details
    Enemy enemy1({(float)150, 50}, {50.0f, 50.0f}, 5.0f, enemy1.SetColor(5.0f));
    Enemy enemy2({(float)300, 50}, {50.0f, 50.0f}, 7.0f, enemy2.SetColor(7.0f));
    Enemy enemy3({(float)350, 50}, {50.0f, 50.0f}, 9.0f, enemy3.SetColor(9.0f));
    Enemy enemy4({(float)500, 50}, {50.0f, 50.0f}, 5.0f, enemy4.SetColor(5.0f));
    Enemy enemy5({(float)550, 150}, {150.0f, 50.0f}, 9.0f, enemy5.SetColor(9.0f));
    Enemy enemy6({(float)700, 50}, {50.0f, 50.0f}, 5.0f, enemy6.SetColor(5.0f));
    Enemy enemy7({(float)900, 50}, {150.0f, 50.0f}, 5.0f, enemy7.SetColor(9.0f));
    Enemy enemy8({(float)1050, 50}, {150.0f, 50.0f}, 7.0f, enemy8.SetColor(7.0f));
    Enemy enemy9({(float)1300, 50}, {100.0f, 50.0f}, 9.0f, enemy9.SetColor(9.0f));

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(!gameOver && !wonGame)
        {
            if(IsKeyDown(KEY_RIGHT)&& player.GetPosition().x < screenWidth - player.GetRadius())
            player.Move({5,0});

            if(IsKeyDown(KEY_LEFT)&& player.GetPosition().x <= screenWidth - player.GetRadius())
            player.Move({-5,0});
        }

        if(enemy1.CheckCollision(player.GetPosition(), player.GetRadius())
        || enemy2.CheckCollision(player.GetPosition(), player.GetRadius())
        || enemy3.CheckCollision(player.GetPosition(), player.GetRadius())
        || enemy4.CheckCollision(player.GetPosition(), player.GetRadius())
        || enemy5.CheckCollision(player.GetPosition(), player.GetRadius())
        || enemy6.CheckCollision(player.GetPosition(), player.GetRadius())
        || enemy7.CheckCollision(player.GetPosition(), player.GetRadius())
        || enemy8.CheckCollision(player.GetPosition(), player.GetRadius())
        || enemy9.CheckCollision(player.GetPosition(), player.GetRadius()))
        {
            lives = lives - 1;
            if(lives <= 0)
            {
                gameOver = true;
                PlaySound(sound);//Plays Sound When 'Game Over'
            }
                
            player.ChangeColour(lives); //Changes Player color based on lives remaining
            player.Reset(); //When player dies, this resets them to the beginning
        }

        if(player.Finish(finishLineX) == true) //Checks for Player making to the End
        {
            wonGame = true;
        }
    
        
        
        // Update
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
        if(!gameOver && !wonGame)
        {
            enemy1.Update();
            enemy2.Update();
            enemy3.Update();

            enemy4.Update();
            enemy5.Update();
            enemy6.Update();

            enemy7.Update();
            enemy8.Update();
            enemy9.Update();
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLUE);
        DrawTexture(background, 0, 0, WHITE); //Draw Backgrounf Texture          
            
        player.Draw(); //Draw Player Texture
        
        //Ground
        DrawRectangle(0, (((screenHeight/2)+50)+player.GetRadius()), screenWidth, (screenHeight/2)+50, RED);
        //Finish Line
        DrawTexture(finishLine, screenWidth-300, (((screenHeight/2)+50)+player.GetRadius()), WHITE);

        //Prints HUD to show Lives
        DrawText(TextFormat("Lives: %i", lives), 10,10,50, player.ChangeColour(lives));

        //Draws Eneies onto Screen
        enemy1.Draw();
        enemy2.Draw();
        enemy3.Draw();

        enemy4.Draw();
        enemy5.Draw();
        enemy6.Draw();
        
        enemy7.Draw();
        enemy8.Draw();
        enemy9.Draw();


        if(gameOver)
        {
            DrawTexture(gameOverScr, 0, 0, WHITE);
        }

        if(wonGame)
        {
            DrawTexture(winnerScreen, 0, 0, WHITE);
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
    UnloadSound(sound);
    CloseAudioDevice();
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

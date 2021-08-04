/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"

const int TILE_SIZE = 16;



int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screen_width = 80*TILE_SIZE;
    int screen_height = 50*TILE_SIZE;
    Vector2 hero_pos = {10,10};



    InitWindow(screen_width, screen_height, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
        {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);


        DrawRectangle(hero_pos.x
        *TILE_SIZE,hero_pos.y*TILE_SIZE,TILE_SIZE,TILE_SIZE,RED);
        if (IsKeyPressed(KEY_W)) {
            hero_pos.y -=1;
        }
        if (IsKeyPressed(KEY_S)) {
            hero_pos.y +=1;
        }
        if (IsKeyPressed(KEY_A)) {
            hero_pos.x -=1;
        }
        if (IsKeyPressed(KEY_D)) {
            hero_pos.x +=1;
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

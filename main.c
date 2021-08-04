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
const int MAP_W = 80;
const int MAP_H = 50;

int map[MAP_W][MAP_H];

void set_map_cell(int x, int y, int value) {
    map[x][y] = value;
}

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screen_width = MAP_W*TILE_SIZE;
    int screen_height = MAP_H*TILE_SIZE;
    Vector2 hero_pos = {10,10};


    //map[20][20] = 1;
    for (int i = 0; i < 10; ++i) {
        set_map_cell(i,i,1);
    }




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

        for (int i = 0; i < MAP_H; ++i) {
            for (int j = 0; j < MAP_W; ++j) {
                if ( map[j][i] == 1) {
                    DrawCircle((j+0.5)*TILE_SIZE,(i+0.5)*TILE_SIZE,TILE_SIZE/2,BLUE);
                }
            }
        }

        DrawRectangle(hero_pos.x
        *TILE_SIZE,hero_pos.y*TILE_SIZE,TILE_SIZE,TILE_SIZE,RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
        }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

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

#include "map.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screen_width = MAP_W*TILE_SIZE;
    int screen_height = MAP_H*TILE_SIZE;
    Vector2 hero_pos = {10,10};

    Vector2 potion_pos = {15,20};
    bool potion_used = false;


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

        int dx = 0;
        int dy = 0;

        if (IsKeyPressed(KEY_W)) {
            //hero_pos.y -=1;
            dy = -1;
        }
        if (IsKeyPressed(KEY_S)) {
            //hero_pos.y +=1;
            dy=1;
        }
        if (IsKeyPressed(KEY_A)) {
            //hero_pos.x -=1;
            dx = -1;
        }
        if (IsKeyPressed(KEY_D)) {
//            hero_pos.x +=1;
            dx = 1;
        }

        if (dx !=0 || dy != 0) {
            if (can_hero_move(hero_pos.x+dx,hero_pos.y+dy)) {
                hero_pos.x +=dx;
                hero_pos.y +=dy;
                if (hero_pos.x == potion_pos.x && hero_pos.y == potion_pos.y) {
                    potion_used = true;
                }
            }
        }

        for (int i = 0; i < MAP_H; ++i) {
            for (int j = 0; j < MAP_W; ++j) {
                if ( is_wall(j,i)) {
                    DrawCircle((j+0.5)*TILE_SIZE,(i+0.5)*TILE_SIZE,TILE_SIZE/2,BLUE);
                }
            }
        }

        DrawRectangle(hero_pos.x
        *TILE_SIZE,hero_pos.y*TILE_SIZE,TILE_SIZE,TILE_SIZE,RED);

        if(!potion_used) {
            DrawCircle((potion_pos.x+0.5)*TILE_SIZE,(potion_pos.y+0.5)*TILE_SIZE,TILE_SIZE/2,GREEN);
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

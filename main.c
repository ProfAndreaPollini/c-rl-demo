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

typedef struct potion {
    Vector2  pos;
    Color color;
    bool used;
} Potion;

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screen_width = MAP_W*TILE_SIZE;
    int screen_height = MAP_H*TILE_SIZE;
    Vector2 hero_pos = {10,10};
    Color hero_color = RED;
    Potion potion = {
            .pos = { 15,20},
            .used = false,
            .color = GREEN
    };



    Vector2 potion_pos = {15,20};
    bool potion_used = false;

    Vector2 monster_pos = {30,30};
    Color monster_color = VIOLET;


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
            if (can_move(hero_pos.x+dx,hero_pos.y+dy)) {
                hero_pos.x +=dx;
                hero_pos.y +=dy;
                if (hero_pos.x == potion_pos.x && hero_pos.y == potion_pos.y) {
                    potion_used = true;
                    hero_color = BLACK;
                }
            }

            // monster moves
            Vector2 monster_movement;
            if (hero_pos.x > monster_pos.x)
                monster_movement.x = 1;
            if (hero_pos.x < monster_pos.x)
                monster_movement.x = -1;

            if (hero_pos.y > monster_pos.y)
                monster_movement.y = 1;
            if (hero_pos.y < monster_pos.y)
                monster_movement.y = -1;


                if (GetRandomValue(1,10)< 5) {
                    if (can_move(monster_pos.x+monster_movement.x,monster_pos.y)) {
                        monster_pos.x += monster_movement.x;
                    }
                } else  {
                    if (can_move(monster_pos.x,monster_pos.y+monster_movement.y)) {
                        monster_pos.y += monster_movement.y;
                    }
                }
            }
//            monster_pos = Vector2Add(monster_pos,monster_movement);


        for (int i = 0; i < MAP_H; ++i) {
            for (int j = 0; j < MAP_W; ++j) {
                if ( is_wall(j,i)) {
                    DrawCircle((j+0.5)*TILE_SIZE,(i+0.5)*TILE_SIZE,TILE_SIZE/2,BLUE);
                }
            }
        }

        DrawRectangle(hero_pos.x
        *TILE_SIZE,hero_pos.y*TILE_SIZE,TILE_SIZE,TILE_SIZE,hero_color);

        DrawRectangle(monster_pos.x
        *TILE_SIZE,monster_pos.y*TILE_SIZE,TILE_SIZE,TILE_SIZE,monster_color);

        if(!potion_used) {
            DrawCircle((potion.pos.x+0.5)*TILE_SIZE,(potion.pos.y+0.5)*TILE_SIZE,TILE_SIZE/2,potion.color);
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

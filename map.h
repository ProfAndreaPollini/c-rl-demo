//
// Created by pollini on 04/08/2021.
//

#ifndef C_RL_DEMO_MAP_H
#define C_RL_DEMO_MAP_H

#include<stdbool.h>


static const int TILE_SIZE = 16;
static const int MAP_W = 80;
static const int MAP_H = 50;

void set_map_cell(int x, int y, int value);
bool can_hero_move(int x, int y);
bool is_wall(int x, int y);

#endif //C_RL_DEMO_MAP_H

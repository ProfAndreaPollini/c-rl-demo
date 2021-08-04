//
// Created by pollini on 04/08/2021.
//

#include "map.h"



int map[MAP_W][MAP_H];


void set_map_cell(int x, int y, int value) {
    map[x][y] = value;
}

bool can_hero_move(int x, int y) {
    return map[x][y] == 0;
}

bool is_wall(int x, int y) {
    return map[x][y] == 1;
}

#pragma once

#include <stdbool.h>


struct Wall* walls;
struct Assignment* assignment;

bool isWall;
bool isFruit;

typedef struct Snake {
    int x;
    int y;
} Snake;

struct Wall {
    int x;
    int y;
    char shape;
}; 

struct Assignment {
    int x;
    int y;
    char shape;

};

//
//void destroyWalls() {
//  free(walls);
//}
//
//void destroyFruits() {
//    free(fruits);
//}

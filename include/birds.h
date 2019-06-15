/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Birds
*/

#ifndef BIRDS_H_
#define BIRDS_H_

#include "global.h"

typedef struct bird {
    int id;
    int is_alive;
    int begin_position;
    int direction;
    sfClock *clock[2];
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
} bird_t;

#define YELLOW_BIRD 1
#define RED_BIRD 2
#define BLUE_BIRD 3
#define GREY_BIRD 4
#define YELLOW_BIRD_A 5
#define RED_BIRD_A 6
#define BLUE_BIRD_A 7
#define GREY_BIRD_A 8
#define YELLOW_BIRD_B 9
#define RED_BIRD_B 10
#define BLUE_BIRD_B 11
#define GREY_BIRD_B 12

#endif

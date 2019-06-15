/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Functions to update birds
*/

#include "global.h"

static const float spend_time[][2] = {
    {0.01, 0.1},
    {0.01, 0.1},
    {0.01, 0.05},
    {0.01, 0.08},
    {0.01, 0.1},
    {0.01, 0.1},
    {0.01, 0.05},
    {0.01, 0.08},
    {0.01, 0.1},
    {0.01, 0.1},
    {0.01, 0.05},
    {0.01, 0.08}
};

static const int set_x[] = {
    8,
    12,
    10,
    18,
    10,
    16,
    8,
    12,
    12,
    16,
    6,
    8
};

static const float (*set_y[])(float x, int begin_position) = {
    &set_y_yellow_bird,
    &set_y_red_bird,
    &set_y_blue_bird,
    &set_y_grey_bird,
    &set_y_yellow_bird,
    &set_y_red_bird,
    &set_y_blue_bird,
    &set_y_grey_bird,
    &set_y_yellow_bird,
    &set_y_red_bird,
    &set_y_blue_bird,
    &set_y_grey_bird
};

static sfVector2f set_move(sfVector2f move, bird_t bird)
{
    move.x += bird.direction ? -set_x[bird.id - 1] : set_x[bird.id - 1];
    move.y = set_y[bird.id - 1](move.x, bird.begin_position);
    return (move);
}

bird_t update_bird(bird_t bird)
{
    sfVector2f move = sfSprite_getPosition(bird.sprite);

    if (!bird.is_alive)
        return (bird);
    if (sfTime_asSeconds(sfClock_getElapsedTime(bird.clock[CLOCK_MOVE])) >
    spend_time[bird.id - 1][0]) {
        move = set_move(move, bird);
        sfSprite_setPosition(bird.sprite, move);
        sfClock_restart(bird.clock[CLOCK_MOVE]);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(bird.clock[CLOCK_ANIM])) >
    spend_time[bird.id - 1][1]) {
        if (bird.rect.left >= 175 * 3)
            bird.rect.left = 0;
        else
            bird.rect.left += 175;
        sfSprite_setTextureRect(bird.sprite, bird.rect);
        sfClock_restart(bird.clock[CLOCK_ANIM]);
    }
    return (bird);
}

void refresh(global_t *global)
{
    game_t *here = global->game;

    if (sfTime_asSeconds(sfClock_getElapsedTime(here->clock)) >
    here->launcher_time)
        if (here->launcher < here->total_birds) {
            here->birds[here->launcher].is_alive = 1;
            here->launcher++;
            here->launcher_time = rand() % 500 / 200 + 0.6;
            sfClock_restart(here->clock);
        } else if (here->launcher >= here->total_birds &&
        !here->birds[here->total_birds - 1].is_alive &&
        !here->birds[here->total_birds - 1].is_alive) {
            global->scene = LEVEL_END;
            global->levels->is_locked[global->level] = global->level > 15 ?
            1 : 0;
        }
}

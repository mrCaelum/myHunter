/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Functions to control birds
*/

#include "global.h"

static const char *file[][2] = {
    {"resources/yellow_bird_l.png", "resources/yellow_bird_r.png"},
    {"resources/red_bird_l.png", "resources/red_bird_r.png"},
    {"resources/blue_bird_l.png", "resources/blue_bird_r.png"},
    {"resources/grey_bird_l.png", "resources/grey_bird_r.png"},
    {"resources/a_yellow_bird_l.png", "resources/a_yellow_bird_r.png"},
    {"resources/a_red_bird_l.png", "resources/a_red_bird_r.png"},
    {"resources/a_blue_bird_l.png", "resources/a_blue_bird_r.png"},
    {"resources/a_grey_bird_l.png", "resources/a_grey_bird_r.png"},
    {"resources/b_yellow_bird_l.png", "resources/b_yellow_bird_r.png"},
    {"resources/b_red_bird_l.png", "resources/b_red_bird_r.png"},
    {"resources/b_blue_bird_l.png", "resources/b_blue_bird_r.png"},
    {"resources/b_grey_bird_l.png", "resources/b_grey_bird_r.png"}
};

static const sfVector2f dim[] = {
    {175, 120},
    {175, 120},
    {175, 126},
    {175, 124},
    {175, 120},
    {175, 120},
    {175, 126},
    {175, 124},
    {175, 120},
    {175, 120},
    {175, 126},
    {175, 124}
};

bird_t create_bird(int id)
{
    bird_t bird;
    sfVector2f pos;

    bird.id = id;
    bird.is_alive = 0;
    bird.begin_position = rand() % 600 + 100;
    bird.direction = rand() % 2;
    pos.x = bird.direction ? 1920 : -175;
    pos.y = bird.begin_position;
    bird.clock[CLOCK_MOVE] = sfClock_create();
    bird.clock[CLOCK_ANIM] = sfClock_create();
    bird.texture = sfTexture_createFromFile(file[id - 1][bird.direction], NULL);
    bird.rect = setup_rect(dim[id - 1].x, dim[id - 1].y);
    bird.sprite = sfSprite_create();
    sfSprite_setTexture(bird.sprite, bird.texture, sfTrue);
    sfSprite_setTextureRect(bird.sprite, bird.rect);
    sfSprite_setPosition(bird.sprite, pos);
    return (bird);
}

void kill_bird(bird_t *bird)
{
    bird->is_alive = 0;
    destroy_bird(bird);
}

void destroy_bird(bird_t *bird)
{
    sfClock_destroy(bird->clock[CLOCK_MOVE]);
    sfClock_destroy(bird->clock[CLOCK_ANIM]);
    sfSprite_destroy(bird->sprite);
    sfTexture_destroy(bird->texture);
}

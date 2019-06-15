/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Function to load a level
*/

#include "global.h"
#include "levels.h"

static int get_total_birds(int id)
{
    int counter = 0;

    for (; gen_level[id][counter]; counter++);
    return (counter);
}

static void set_lifebar(life_bar_t *lifebar)
{
    lifebar->texture = sfTexture_createFromFile("resources/hearts.png", NULL);
    lifebar->sprite = sfSprite_create();
    lifebar->rect.left = 0;
    lifebar->rect.top = 0;
    lifebar->rect.width = 240;
    lifebar->rect.height = 72;
    lifebar->pos.x = 30;
    lifebar->pos.y = 30;
}

int level_loader(global_t *global)
{
    game_t *here = global->game;

    here->clock = sfClock_create();
    here->texture = sfTexture_createFromFile(file[global->level - 1], NULL);
    here->sprite = sfSprite_create();
    sfSprite_setTexture(here->sprite, here->texture, sfTrue);
    here->total_birds = get_total_birds(global->level - 1);
    here->birds = malloc(sizeof(bird_t) * here->total_birds);
    for (int i = 0; i < here->total_birds; i++)
        here->birds[i] = create_bird(gen_level[global->level - 1][i]);
    here->launcher = 0;
    here->launcher_time = rand() % 500 / 200 + 1.5;
    here->life = 3;
    set_lifebar(&here->life_bar);
    sfSprite_setTexture(here->life_bar.sprite, here->life_bar.texture, sfTrue);
    sfSprite_setTextureRect(here->life_bar.sprite, here->life_bar.rect);
    sfSprite_setPosition(here->life_bar.sprite, here->life_bar.pos);
    return (0);
}

int level_unloader(game_t *here)
{
    for (size_t i = 0; i < here->total_birds; i++)
        if (here->birds[i].is_alive)
            kill_bird(&here->birds[i]);
    free(here->birds);
    sfClock_destroy(here->clock);
    sfSprite_destroy(here->life_bar.sprite);
    sfTexture_destroy(here->life_bar.texture);
    sfSprite_destroy(here->sprite);
    sfTexture_destroy(here->texture);
    return (0);
}

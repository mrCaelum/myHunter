/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Game scene
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

static int is_bird_outside_map(bird_t bird)
{
    sfVector2f pos = sfSprite_getPosition(bird.sprite);

    if (!bird.direction && pos.x > 1920)
        return (1);
    if (bird.direction && pos.x < -175)
        return (1);
    return (0);
}

static void events_on_click(global_t *global)
{
    game_t *here = global->game;

    for (int i = 0; i < here->total_birds; i++) {
        if (here->birds[i].is_alive && here->birds[i].id <= 4 &&
        is_mouse_hovering(global, here->birds[i].sprite)) {
            kill_bird(&here->birds[i]);
        } else if (here->birds[i].is_alive && here->birds[i].id > 4 &&
        is_mouse_hovering(global, here->birds[i].sprite)) {
            here->birds[i].id -= 4;
            sfTexture_destroy(here->birds[i].texture);
            here->birds[i].texture = sfTexture_createFromFile(
            file[here->birds[i].id - 1][here->birds[i].direction], NULL);
            sfSprite_setTexture(here->birds[i].sprite, here->birds[i].texture,
            sfTrue);
            sfSprite_setTextureRect(here->birds[i].sprite,
            here->birds[i].rect);
        }
    }
}

static int game_events(global_t *global)
{
    game_t *here = global->game;

    if (global->event.type == sfEvtClosed)
        sfRenderWindow_close(global->window);
    if (global->event.type == sfEvtMouseButtonPressed) {
        events_on_click(global);
        sfMusic_stop(global->shot);
        sfMusic_play(global->shot);
    }
}

static int game_draw(global_t *global)
{
    game_t *here = global->game;

    sfRenderWindow_clear(global->window, sfWhite);
    sfRenderWindow_drawSprite(global->window, here->sprite, NULL);
    sfRenderWindow_drawSprite(global->window, here->life_bar.sprite, NULL);
    for (int i = 0; i < here->total_birds; i++)
        if (here->birds[i].is_alive)
            sfRenderWindow_drawSprite(global->window, here->birds[i].sprite,
            NULL);
}

int scene_game(global_t *global)
{
    game_t *here = global->game;

    while (sfRenderWindow_pollEvent(global->window, &global->event))
        game_events(global);
    refresh(global);
    for (int i = 0; i < here->total_birds; i++)
        here->birds[i] = update_bird(here->birds[i]);
    game_draw(global);
    for (int i = 0; i < here->total_birds; i++)
        if (here->birds[i].is_alive && is_bird_outside_map(here->birds[i])) {
            loose_one_life(here);
            kill_bird(&here->birds[i]);
        }
    if (here->life <= 0)
        global->scene = LEVEL_END;
    if (global->scene != INGAME)
        level_unloader(here);
}

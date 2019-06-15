/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Help scene
*/

#include "global.h"

static int help_events(global_t *global)
{
    menu_help_t *here = global->help;

    if (global->event.type == sfEvtClosed)
        sfRenderWindow_close(global->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        global->scene = MENU;
    if (here->bird_is_alive && global->event.type == sfEvtMouseButtonPressed &&
    is_mouse_hovering(global, here->sprites[1]))
        here->bird_is_alive = 0;
}

static int help_draw(global_t *global)
{
    menu_help_t *here = global->help;

    sfRenderWindow_clear(global->window, sfWhite);
    sfRenderWindow_drawSprite(global->window, here->sprites[0], NULL);
    if (here->bird_is_alive)
        sfRenderWindow_drawSprite(global->window, here->sprites[1], NULL);
}

int scene_help(global_t *global)
{
    menu_help_t *here = global->help;

    while (sfRenderWindow_pollEvent(global->window, &global->event))
        help_events(global);
    if (here->bird_is_alive &&
    sfTime_asSeconds(sfClock_getElapsedTime(here->clock)) > 0.1) {
        sfSprite_setTextureRect(here->sprites[1],
        (sfIntRect){here->anim * 175, 0, 175, 120});
        sfClock_restart(here->clock);
        here->anim = here->anim == 3 ? 0 : here->anim + 1;
    }
    help_draw(global);
}

int setup_help(global_t *global)
{
    menu_help_t *here = global->help;

    here->bird_is_alive = 1;
    here->clock = sfClock_create();
    here->textures = malloc(sizeof(sfTexture *) * 2);
    here->sprites = malloc(sizeof(sfSprite *) * 2);
    here->textures[0] = sfTexture_createFromFile("resources/help.png", NULL);
    here->textures[1] =
        sfTexture_createFromFile("resources/yellow_bird_r.png", NULL);
    for (int i = 0; i < 2; i++) {
        here->sprites[i] = sfSprite_create();
        sfSprite_setTexture(here->sprites[i], here->textures[i], sfTrue);
    }
    sfSprite_setPosition(here->sprites[1], (sfVector2f){1100, 400});
    sfSprite_setTextureRect(here->sprites[1], (sfIntRect){0, 0, 175, 120});
    return (0);
}

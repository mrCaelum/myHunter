/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Levels scene
*/

#include "global.h"

static void check_birds(global_t *global, menu_levels_t *here)
{
    for (int i = 0; i < 16; i++) {
        if (global->event.type == sfEvtMouseButtonPressed &&
        !here->is_locked[i] &&
        is_mouse_hovering(global, here->sprites[i + 3])) {
            global->level = i + 1;
            global->scene = INGAME;
        }
        if (here->is_locked[i])
            sfSprite_setTextureRect(here->sprites[i + 3],
            (sfIntRect){400, 0, 200, 200});
        else if (is_mouse_hovering(global, here->sprites[i + 3]))
            sfSprite_setTextureRect(here->sprites[i + 3],
            (sfIntRect){200, 0, 200, 200});
        else
            sfSprite_setTextureRect(here->sprites[i + 3],
            (sfIntRect){0, 0, 200, 200});
    }
}

static int levels_events(global_t *global)
{
    menu_levels_t *here = global->levels;

    if (global->event.type == sfEvtClosed)
        sfRenderWindow_close(global->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        global->scene = MENU;
    if (global->event.type == sfEvtMouseButtonPressed) {
        if (is_mouse_hovering(global, here->sprites[1]))
            global->scene = MENU;
    }
    check_birds(global, here);
}

static int levels_draw(global_t *global)
{
    menu_levels_t *here = global->levels;

    sfRenderWindow_clear(global->window, sfWhite);
    sfRenderWindow_drawSprite(global->window, here->sprites[0], NULL);
    sfRenderWindow_drawSprite(global->window,
    here->sprites[1 + is_mouse_hovering(global, here->sprites[1])], NULL);
    for (int i = 3; i < 19; i++)
        sfRenderWindow_drawSprite(global->window, here->sprites[i], NULL);
}

int scene_levels(global_t *global)
{
    menu_levels_t *here = global->levels;

    while (sfRenderWindow_pollEvent(global->window, &global->event))
        levels_events(global);
    levels_draw(global);
    if (global->scene == INGAME)
        level_loader(global);
}

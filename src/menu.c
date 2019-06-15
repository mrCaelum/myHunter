/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Menu scene
*/

#include "global.h"

static int menu_events(global_t *global)
{
    menu_t *here = global->menu;

    if (global->event.type == sfEvtClosed ||
    sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(global->window);
    if (global->event.type == sfEvtMouseButtonPressed) {
        if (is_mouse_hovering(global, here->sprites[1]))
            global->scene = LEVELS;
    }
}

static int menu_draw(global_t *global)
{
    menu_t *here = global->menu;

    sfRenderWindow_clear(global->window, sfWhite);
    sfRenderWindow_drawSprite(global->window, here->sprites[0], NULL);
    sfRenderWindow_drawSprite(global->window,
    here->sprites[1 + is_mouse_hovering(global, here->sprites[1])], NULL);
}

int scene_menu(global_t *global)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event))
        menu_events(global);
    menu_draw(global);
    if (global->scene == INGAME)
        level_loader(global);
}

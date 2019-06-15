/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** lvl_end scene
*/

#include "global.h"

static void update_buttons(global_t *global, menu_lvlend_t *here)
{
    if (is_mouse_hovering(global, here->sprites[1]))
        sfSprite_setTextureRect(here->sprites[1],
        (sfIntRect){200, 0, 200, 200});
    else
        sfSprite_setTextureRect(here->sprites[1], (sfIntRect){0, 0, 200, 200});
    if (is_mouse_hovering(global, here->sprites[2]))
        sfSprite_setTextureRect(here->sprites[2],
        (sfIntRect){200, 0, 200, 200});
    else
        sfSprite_setTextureRect(here->sprites[2], (sfIntRect){0, 0, 200, 200});
    if (global->levels->is_locked[global->level])
        sfSprite_setTextureRect(here->sprites[3],
        (sfIntRect){400, 0, 200, 200});
    else if (is_mouse_hovering(global, here->sprites[3]))
        sfSprite_setTextureRect(here->sprites[3],
        (sfIntRect){200, 0, 200, 200});
    else
        sfSprite_setTextureRect(here->sprites[3], (sfIntRect){0, 0, 200, 200});
}

static int lvlend_events(global_t *global)
{
    menu_lvlend_t *here = global->menu_lvlend;

    if (global->event.type == sfEvtClosed)
        sfRenderWindow_close(global->window);
    if (global->event.type == sfEvtMouseButtonPressed) {
        if (is_mouse_hovering(global, here->sprites[1]))
            global->scene = MENU;
        if (is_mouse_hovering(global, here->sprites[2]))
            global->scene = INGAME;
        if (is_mouse_hovering(global, here->sprites[3]) &&
        !global->levels->is_locked[global->level]) {
            global->level++;
            global->scene = INGAME;
        }
    }
    update_buttons(global, here);
}

static int lvlend_draw(global_t *global)
{
    menu_lvlend_t *here = global->menu_lvlend;

    sfRenderWindow_clear(global->window, sfWhite);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(global->window, here->sprites[i], NULL);
}

int scene_lvlend(global_t *global)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event))
        lvlend_events(global);
    lvlend_draw(global);
    if (global->scene == INGAME)
        level_loader(global);
}

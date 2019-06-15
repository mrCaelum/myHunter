/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Setup menu
*/

#include "global.h"

static sfVector2f setup_button_position(global_t *global, int i)
{
    sfVector2f position;
    sfVector2u window_size = sfRenderWindow_getSize(global->window);

    position.x = window_size.x / 2 - 200 / 2 + 300 * (i - 2);
    position.y = window_size.y / 2 - 200 / 2;
    return (position);
}

int setup_lvlend(global_t *global)
{
    menu_lvlend_t *here = global->menu_lvlend;

    here->textures = malloc(sizeof(sfTexture *) * 4);
    here->sprites = malloc(sizeof(sfSprite *) * 4);
    here->textures[0] = sfTexture_createFromFile("resources/menu.jpg", NULL);
    here->textures[1] = sfTexture_createFromFile("resources/home_btn.png", NULL);
    here->textures[2] = sfTexture_createFromFile("resources/restart_btn.png", NULL);
    here->textures[3] = sfTexture_createFromFile("resources/next_btn.png", NULL);
    for (int i = 0; i < 4; i++) {
        here->sprites[i] = sfSprite_create();
        sfSprite_setTexture(here->sprites[i], here->textures[i], sfTrue);
        if (i != 0) {
            sfSprite_setPosition(here->sprites[i],
            setup_button_position(global, i));
            sfSprite_setTextureRect(here->sprites[i],
            (sfIntRect){0, 0, 200, 200});
        }
    }
    return (0);
}

/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Setup menu
*/

#include "global.h"

static sfVector2f setup_button_position(global_t *global)
{
    sfVector2f position;
    sfVector2u window_size = sfRenderWindow_getSize(global->window);

    position.x = window_size.x / 2 - 518 / 2;
    position.y = window_size.y / 2 - 118 / 2;
    return (position);
}

int setup_menu(global_t *global)
{
    menu_t *here = global->menu;

    here->textures = malloc(sizeof(sfTexture *) * 3);
    here->sprites = malloc(sizeof(sfSprite *) * 3);
    here->textures[0] = sfTexture_createFromFile("resources/menu.jpg", NULL);
    here->textures[1] = sfTexture_createFromFile("resources/button.png", NULL);
    here->textures[2] =
        sfTexture_createFromFile("resources/button_clicked.png", NULL);
    for (int i = 0; i < 3; i++)
        here->sprites[i] = sfSprite_create();
    for (int i = 0; i < 3; i++)
        sfSprite_setTexture(here->sprites[i], here->textures[i], sfTrue);
    for (int i = 1; i < 3; i++)
        sfSprite_setPosition(here->sprites[i], setup_button_position(global));
    return (0);
}

/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Setup function
*/

#include "global.h"

static const int (*scenes[])(global_t *global) = {
    &setup_menu,
    &setup_levels,
    &setup_lvlend,
    &setup_help,
    NULL
};

global_t setup_global(global_t global, char const *str)
{
    sfVideoMode mode = {1920, 1080, 32};

    global.window = sfRenderWindow_create(mode, "my_hunter",
    sfResize | sfClose | sfFullscreen, NULL);
    global.scene = str[0] == '-' && str[1] == 'h' ? HELP : MENU;
    global.menu = malloc(2 * sizeof(menu_t *));
    global.levels = malloc(SIZEOF_LEVELS_MENU);
    global.menu_lvlend = malloc(4 * sizeof(menu_lvlend_t *));
    global.help = malloc(4 * sizeof(menu_help_t *));
    global.game = malloc(SIZEOF_GAME);
    global.shot = sfMusic_createFromFile("resources/shot.wav");
    for (int i = 0; scenes[i]; i++)
        scenes[i](&global);
    global.cursor_texture =
        sfTexture_createFromFile("resources/target.png", NULL);
    global.cursor = sfSprite_create();
    sfSprite_setTexture(global.cursor, global.cursor_texture, sfTrue);
    return (global);
}

void destroy(global_t *global)
{
    sfMusic_destroy(global->shot);
    free(global->game);
    free(global->help);
    free(global->menu_lvlend);
    free(global->levels);
    free(global->menu);
    sfSprite_destroy(global->cursor);
    sfTexture_destroy(global->cursor_texture);
    sfRenderWindow_destroy(global->window);
}

sfIntRect setup_rect(int x, int y)
{
    sfIntRect rect;

    rect.width = x;
    rect.height = y;
    rect.left = 0;
    rect.top = 0;
    return (rect);
}

/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Setup menu
*/

#include "global.h"

static const char *file[] = {
    "resources/menu.jpg",
    "resources/lbutton.png",
    "resources/lbutton_clicked.png"
};

static const char *btn_file[] = {
    "resources/lvl1.png",
    "resources/lvl2.png",
    "resources/lvl3.png",
    "resources/lvl4.png",
    "resources/lvl5.png",
    "resources/lvl6.png",
    "resources/lvl7.png",
    "resources/lvl8.png",
    "resources/lvl9.png",
    "resources/lvl10.png",
    "resources/lvl11.png",
    "resources/lvl12.png",
    "resources/lvl13.png",
    "resources/lvl14.png",
    "resources/lvl15.png",
    "resources/lvl16.png"
};

static sfVector2f setup_button_position(global_t *global)
{
    sfVector2f position;
    sfVector2u window_size = sfRenderWindow_getSize(global->window);

    position.x = window_size.x - 150;
    position.y = window_size.y - 150;
    return (position);
}

static sfVector2f set_pos(int i)
{
    sfVector2f pos;

    pos.x = 410 + 300 * (i % 4);
    pos.y = 80 + 220 * (i / 4);
    return (pos);
}

static sfIntRect set_rect(sfIntRect rect)
{
    rect.left = 0;
    rect.top = 0;
    rect.width = 200;
    rect.height = 200;
    return (rect);
}

static int get_levels_unlocked(void)
{
    int fd = open(SAVE_FILE, O_RDONLY);
    char buffer;

    if (fd < 0)
        return (0);
    if (!read(fd, &buffer, 1) || buffer < 32 || buffer > 48) {
        close(fd);
        return (0);
    }
    close(fd);
    return (buffer - 32);
}

int setup_levels(global_t *global)
{
    menu_levels_t *here = global->levels;

    here->textures = malloc(sizeof(sfTexture *) * 19);
    here->sprites = malloc(sizeof(sfSprite *) * 19);
    here->is_locked = malloc(sizeof(int) * 16);
    for (int i = 0; i < 3; i++) {
        here->textures[i] = sfTexture_createFromFile(file[i], NULL);
        here->sprites[i] = sfSprite_create();
        sfSprite_setTexture(here->sprites[i], here->textures[i], sfTrue);
        if (i == 1 || i == 2) {
            sfSprite_setPosition(here->sprites[i],
            setup_button_position(global));
        }
    }
    for (int i = 0; i < 16; i++) {
        here->textures[i + 3] = sfTexture_createFromFile(btn_file[i], NULL);
        here->sprites[i + 3] = sfSprite_create();
        sfSprite_setTexture(here->sprites[i + 3], here->textures[i + 3],
        sfTrue);
        sfSprite_setTextureRect(here->sprites[i + 3],
        (sfIntRect){0, 0, 200, 200});
        sfSprite_setPosition(here->sprites[i + 3], set_pos(i));
        here->is_locked[i] = 1;
    }
    for (int i = 0; i < get_levels_unlocked(); i++)
        here->is_locked[i] = 0;
    here->is_locked[0] = 0;
    return (0);
}

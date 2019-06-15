/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Event functions
*/

#include "global.h"

int is_mouse_hovering(global_t *global, sfSprite *sprite)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(global->window);
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite);

    if (mouse_pos.x >= sprite_rect.left && mouse_pos.x <= sprite_rect.left +
    sprite_rect.width && mouse_pos.y >= sprite_rect.top && mouse_pos.y <=
    sprite_rect.top + sprite_rect.height)
        return (1);
    return (0);
}

sfVector2f set_to_middle(global_t *global, sfText *text)
{
    sfVector2u window_size = sfRenderWindow_getSize(global->window);
    sfFloatRect text_box = sfText_getGlobalBounds(text);
    sfVector2f position;

    position.y = 200;
    position.x = window_size.x / 2 - text_box.width / 2;
    return (position);
}

sfVector2f text_center_button(sfSprite *sprite, sfText *text)
{
    sfFloatRect btn_box = sfSprite_getGlobalBounds(sprite);
    sfFloatRect text_box = sfText_getGlobalBounds(text);
    sfVector2f position;

    position.x = btn_box.left + btn_box.width / 2 - text_box.width / 2;
    position.y = btn_box.top + btn_box.height / 2 - text_box.height / 2 - 10;
    return (position);
}

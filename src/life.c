/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Life
*/

#include "global.h"

void loose_one_life(game_t *here)
{
    here->life--;
    here->life_bar.rect.left += 240;
    sfSprite_setTextureRect(here->life_bar.sprite, here->life_bar.rect);
}

/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Function to load scenes
*/

#include "global.h"

static const call_element_t scenes[] = {
    {MENU, &scene_menu},
    {LEVELS, &scene_levels},
    {LEVEL_END, &scene_lvlend},
    {INGAME, &scene_game},
    {HELP, &scene_help},
    {0, NULL}
};

int draw_scene(global_t *global)
{
    for (int i = 0; scenes[i].id; i++)
        if (scenes[i].id == global->scene)
            return (scenes[i].call_it(global));
}

/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Function to set Y position of each bird
*/

#include "global.h"

float set_y_yellow_bird(float x, int begin_position)
{
    return (cos(x / 120) * 60 + begin_position);
}

float set_y_red_bird(float x, int begin_position)
{
    return (cos(x / 200) * 40 + begin_position);
}

float set_y_blue_bird(float x, int begin_position)
{
    return (cos(x / 70) * 180 + begin_position);
}

float set_y_grey_bird(float x, int begin_position)
{
    return (cos(x / 100) * 80 + begin_position);
}

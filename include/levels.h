/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Def levels
*/

#ifndef LEVELS_H_
#define LEVELS_H_

#define YELLOW_BIRD 1
#define RED_BIRD 2
#define BLUE_BIRD 3
#define GREY_BIRD 4
#define YELLOW_BIRD_A 5
#define RED_BIRD_A 6
#define BLUE_BIRD_A 7
#define GREY_BIRD_A 8
#define YELLOW_BIRD_B 9
#define RED_BIRD_B 10
#define BLUE_BIRD_B 11
#define GREY_BIRD_B 12

const char *file[] = {"resources/lvl1_bg.png", "resources/lvl2_bg.png",
    "resources/lvl3_bg.png", "resources/lvl4_bg.png", "resources/lvl5_bg.png",
    "resources/lvl6_bg.png", "resources/lvl7_bg.png", "resources/lvl8_bg.png",
    "resources/lvl9_bg.png", "resources/lvl10_bg.png",
    "resources/lvl11_bg.png", "resources/lvl12_bg.png",
    "resources/lvl13_bg.png", "resources/lvl14_bg.png",
    "resources/lvl15_bg.png", "resources/lvl16_bg.png"};

const int gen_level[][20] = {
    {
        YELLOW_BIRD,
        YELLOW_BIRD,
        YELLOW_BIRD,
        YELLOW_BIRD,
        YELLOW_BIRD,
        YELLOW_BIRD,
        YELLOW_BIRD_A,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        YELLOW_BIRD,
        YELLOW_BIRD,
        YELLOW_BIRD,
        RED_BIRD,
        YELLOW_BIRD,
        RED_BIRD,
        RED_BIRD,
        YELLOW_BIRD,
        RED_BIRD_A,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        YELLOW_BIRD,
        BLUE_BIRD,
        YELLOW_BIRD,
        BLUE_BIRD,
        YELLOW_BIRD,
        YELLOW_BIRD,
        BLUE_BIRD,
        YELLOW_BIRD,
        RED_BIRD_A,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        BLUE_BIRD,
        YELLOW_BIRD,
        YELLOW_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        YELLOW_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        RED_BIRD,
        BLUE_BIRD_A,
        0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        YELLOW_BIRD_B,
        RED_BIRD_A,
        YELLOW_BIRD_A,
        BLUE_BIRD,
        YELLOW_BIRD_B,
        BLUE_BIRD_B,
        YELLOW_BIRD,
        RED_BIRD_A,
        YELLOW_BIRD,
        GREY_BIRD_A,
        0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        RED_BIRD,
        RED_BIRD_A,
        RED_BIRD,
        RED_BIRD_B,
        RED_BIRD,
        RED_BIRD,
        RED_BIRD_B,
        RED_BIRD_B,
        RED_BIRD_A,
        RED_BIRD,
        RED_BIRD,
        RED_BIRD_A,
        0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        RED_BIRD_B,
        YELLOW_BIRD,
        YELLOW_BIRD_B,
        YELLOW_BIRD,
        BLUE_BIRD,
        RED_BIRD,
        YELLOW_BIRD,
        RED_BIRD_B,
        YELLOW_BIRD,
        YELLOW_BIRD,
        GREY_BIRD_A,
        YELLOW_BIRD,
        GREY_BIRD_A,
        0, 0, 0, 0, 0, 0, 0,
    },
    // TODO : create custom levels
    {
        YELLOW_BIRD,
        BLUE_BIRD,
        RED_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        RED_BIRD,
        RED_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        BLUE_BIRD,
        RED_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        RED_BIRD,
        RED_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        BLUE_BIRD,
        RED_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        RED_BIRD,
        RED_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        BLUE_BIRD,
        RED_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        RED_BIRD,
        RED_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        BLUE_BIRD,
        RED_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        RED_BIRD,
        RED_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        BLUE_BIRD,
        RED_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        RED_BIRD,
        RED_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        BLUE_BIRD,
        RED_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        RED_BIRD,
        RED_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        YELLOW_BIRD,
        BLUE_BIRD,
        RED_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        GREY_BIRD,
        RED_BIRD,
        RED_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
        GREY_BIRD_B,
        YELLOW_BIRD,
        RED_BIRD_B,
        RED_BIRD_B,
        YELLOW_BIRD,
        YELLOW_BIRD_B,
        RED_BIRD,
        GREY_BIRD,
        YELLOW_BIRD,
        GREY_BIRD_B,
        GREY_BIRD,
        RED_BIRD_B,
        YELLOW_BIRD,
        BLUE_BIRD_B,
        BLUE_BIRD,
        YELLOW_BIRD_B,
        GREY_BIRD_A,
        GREY_BIRD_B,
        GREY_BIRD_B,
        0
    }
};

#endif

/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Main my_hunter header file
*/

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "id.h"
#include "birds.h"

#define SAVE_FILE "levels.save"

typedef struct life_bar {
    sfIntRect rect;
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
} life_bar_t;

typedef struct menu {
    sfTexture **textures;
    sfSprite **sprites;
} menu_t;

typedef struct menu_levels {
    sfTexture **textures;
    sfSprite **sprites;
    int *is_locked;
} menu_levels_t;

typedef struct menu_lvlend {
    sfTexture **textures;
    sfSprite **sprites;
} menu_lvlend_t;

typedef struct menu_help {
    sfTexture **textures;
    sfSprite **sprites;
    int anim;
    int bird_is_alive;
    sfClock *clock;
} menu_help_t;

typedef struct game {
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    bird_t *birds;
    int total_birds;
    int launcher;
    float launcher_time;
    int life;
    life_bar_t life_bar;
} game_t;

typedef struct global {
    sfRenderWindow *window;
    sfEvent event;
    int scene;
    int level;
    menu_t *menu;
    menu_levels_t *levels;
    menu_lvlend_t *menu_lvlend;
    menu_help_t *help;
    game_t *game;
    sfTexture *cursor_texture;
    sfSprite *cursor;
    sfMusic *loop;
    sfMusic *shot;
} global_t;

typedef struct call_element {
    int id;
    int (*call_it)(global_t *global);
} call_element_t;

#define SIZEOF_LEVELS_MENU (19 * sizeof(sfTexture *) + 19 * sizeof(sfSprite *) + 16 * sizeof(int))
#define SIZEOF_GAME (sizeof(sfClock *) + 2 * sizeof(sfTexture *) + 2 * sizeof(sfSprite *) + 20 * sizeof(bird_t *) + 3 * sizeof(int) + sizeof(float) + sizeof(life_bar_t))

int is_mouse_hovering(global_t *global, sfSprite *sprite);
sfVector2f set_to_middle(global_t *global, sfText *text);
sfVector2f text_center_button(sfSprite *sprite, sfText *text);

global_t setup_global(global_t global, char const *str);
int setup_menu(global_t *global);
int setup_levels(global_t *global);
int setup_lvlend(global_t *global);
int setup_help(global_t *global);
int setup_game(global_t *global);
void destroy(global_t *global);
sfIntRect setup_rect(int x, int y);

int draw_scene(global_t *global);
int scene_menu(global_t *global);
int scene_levels(global_t *global);
int scene_lvlend(global_t *global);
int scene_help(global_t *global);
int scene_game(global_t *global);

int level_loader(global_t *global);
int level_unloader(game_t *here);

bird_t create_bird(int id);
bird_t update_bird(bird_t bird);
void kill_bird(bird_t *bird);
void destroy_bird(bird_t *bird);
void refresh(global_t *global);

float set_y_yellow_bird(float x, int begin_position);
float set_y_red_bird(float x, int begin_position);
float set_y_blue_bird(float x, int begin_position);
float set_y_grey_bird(float x, int begin_position);

void loose_one_life(game_t *here);

#endif

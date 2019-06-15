/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Main function
*/

#include "global.h"

static void print_cursor(global_t *global)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(global->window);
    sfVector2f position;

    position.x = mouse_pos.x - 100;
    position.y = mouse_pos.y - 100;
    sfSprite_setPosition(global->cursor, position);
    sfRenderWindow_drawSprite(global->window, global->cursor, NULL);
}

static void save(global_t *global)
{
    int fd = open(SAVE_FILE, O_WRONLY | O_CREAT);
    char buffer = 32;

    for (int i = 0; !global->levels->is_locked[i]; i++, buffer++);
    write(fd, &buffer, 1);
    write(fd, "\n", 1);
    close(fd);
}

int main(int argc, char const *argv[])
{
    global_t global = setup_global(global, argc > 1 ? argv[1] : "xx");

    srand(time(NULL));
    if (!global.window)
        return (EXIT_FAILURE);
    sfRenderWindow_setFramerateLimit(global.window, 60);
    sfRenderWindow_setMouseCursorVisible(global.window, sfFalse);
    while (sfRenderWindow_isOpen(global.window)) {
        draw_scene(&global);
        print_cursor(&global);
        sfRenderWindow_display(global.window);
    }
    save(&global);
    destroy(&global);
    return (EXIT_SUCCESS);
}

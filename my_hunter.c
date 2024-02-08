/*
** EPITECH PROJECT, 2023
** my_hunter.c
** File description:
** my_hunter.c
*/

#include "include/my_hunt.h"

void draw_stbtn(sprites_stc *sprites, game_stc *stats, SFRW *window, SFE event)
{
    sfIntRect rect;
    sfSprite *btn = sprites->sbutton;

    rect.top = 0;
    rect.left = 770 * stats->anims;
    rect.width = 770;
    rect.height = 360;
    sfSprite_setTextureRect(btn, rect);
    sfRenderWindow_drawSprite(window, btn, NULL);
}

void mmouse(SFRW *window, sfEvent event, sprites_stc *sprites, game_stc *stats)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    int x = mouse.x;
    int y = mouse.y;

    stats->anims = 0;
    if ((x > 740 && x < 1125) && (y > 400 && y < 580)) {
        stats->anims = 1;
        if (event.type == sfEvtMouseButtonPressed) {
            sfMusic_stop(sprites->sm_music);
            play(window, event, sprites, stats);
        }
    }
    draw_stbtn(sprites, stats, window, event);
}

void my_hunter(sprites_stc *sprites, game_stc *stats)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    SFRW *window;
    sfEvent event;
    char str[] = "Dragon Hunter";

    window = sfRenderWindow_create(video_mode, str, sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfMusic_play(sprites->sm_music);
    sfMusic_setLoop(sprites->sm_music, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            closewindow(window, event);
        }
        mmouse(window, event, sprites, stats);
        sfRenderWindow_drawSprite(window, sprites->background, NULL);
        sfRenderWindow_drawText(window, sprites->game_name, NULL);
        sfRenderWindow_drawSprite(window, sprites->sbutton, NULL);
        sfRenderWindow_display(window);
    }
}

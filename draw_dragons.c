/*
** EPITECH PROJECT, 2023
** draw_dragons.c
** File description:
** draw_dragons.c
*/

#include "include/my_hunt.h"

void draw_boss(SFRW *window, game_stc *stats, sprites_stc *sprites)
{
    sfIntRect rect;
    sfSprite *boss = sprites->boss;
    SFVF poscopy = stats->boss_pos;

    rect.top = 0;
    rect.left = 184  * stats->animb;
    rect.width = 184;
    rect.height = 144;
    sfSprite_setTextureRect(boss, rect);
    sfSprite_setPosition(boss, poscopy);
    sfRenderWindow_drawSprite(window, boss, NULL);
}

void draw_dragon(SFRW *window, game_stc *stats, sprites_stc *sprites)
{
    sfIntRect rect;
    sfSprite *dragon = sprites->dragon;
    SFVF poscopy = stats->dragon_pos;

    rect.top = 161;
    rect.left = 191  * stats->anim;
    rect.width = 161;
    rect.height = 185;
    sfSprite_setTextureRect(dragon, rect);
    sfSprite_setPosition(dragon, poscopy);
    sfRenderWindow_drawSprite(window, dragon, NULL);
}

void draw_dragons(SFRW *window, game_stc *stats, sprites_stc *sprites)
{
    draw_dragon(window, stats, sprites);
    if (stats->bossfigth) {
        draw_boss(window, stats, sprites);
    }
}

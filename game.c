/*
** EPITECH PROJECT, 2023
** game.c
** File description:
** game.c
*/

#include "include/my_hunt.h"

static int check_clickd(SFRW *window, sprites_stc *sprites, game_stc *stats)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    int x = stats->dragon_pos.x;
    int y = stats->dragon_pos.y;
    int mx = mouse.x;
    int my = mouse.y;

    if ((mx > x && mx < x + 161) && (my > y && my < y + 191)) {
        stats->dragon_pos.x = -170;
        stats->dragon_pos.y = rand() % 1080;
        if (stats->dragon_pos.y > 890) {
            stats->dragon_pos.y = 890;
        }
        sfSound_play(sprites->dead_sound);
        return 1;
    }
    return 0;
}

static int check_clickb(SFRW *window, sprites_stc *sprites, game_stc *stats)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    int xb = stats->boss_pos.x;
    int yb = stats->boss_pos.y;
    int mx = mouse.x;
    int my = mouse.y;

    if ((mx > xb && mx < xb + 368) && (my > yb && my < yb + 288)) {
        if (stats->boss_hp > 0) {
            return 1;
        }
    }
    return 0;
}

static void draw_health(SFRW *window, sprites_stc *sprites, int hp)
{
    sfIntRect rect;
    sfSprite *health = sprites->health;
    SFVF health_pos = {1820, 20};
    SFVF health_scale = {5, 5};

    rect.top = 0;
    rect.left = 17 * (3 - hp);
    rect.width = 17;
    rect.height = 17;
    sfSprite_setTextureRect(health, rect);
    sfSprite_setPosition(health, health_pos);
    sfSprite_setScale(sprites->health, health_scale);
    sfRenderWindow_drawSprite(window, health, NULL);
}

void death(SFRW *window, SFE event, sprites_stc *sprites, game_stc *stats)
{
    if (stats->hp < 0) {
        stats->hp = 3;
        sfMusic_stop(sprites->g_music);
        sfMusic_play(sprites->end_music);
        game_over(sprites, window, event, stats);
        sfMusic_play(sprites->g_music);
    }
    if (stats->boss_hp == 0) {
        stats->bossfigth = 0;
        stats->boss_pos.x = -300;
        stats->boss_hp = 100;
        sfSound_play(sprites->dead_sound);
    }
}

void render(SFRW *window, SFE event, sprites_stc *sprites, game_stc *stats)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, sprites->background, NULL);
    sfRenderWindow_drawText(window, sprites->game_name, NULL);
    if (stats->bossfigth == 1)
        sfRenderWindow_drawText(window, sprites->boss_text, NULL);
    draw_score(stats->score, window, sprites->score_text);
    draw_health(window, sprites, stats->hp);
    if (event.type == sfEvtMouseButtonPressed) {
        stats->score += check_clickd(window, sprites, stats);
        stats->game_pace = (stats->score + 10) / 10;
        stats->boss_hp -= check_clickb(window, sprites, stats);
    }
    if (stats->score != 0 && stats->score % 20 == 0) {
        stats->bossfigth = 1;
    }
    compute_dragons(stats, sprites);
    death(window, event, sprites, stats);
    draw_dragons(window, stats, sprites);
    sfRenderWindow_display(window);
}

void play(SFRW *window, SFE event, sprites_stc *sprites, game_stc *stats)
{
    SFVF dragon_pos = {-161, 20};
    SFVF boss_pos = {-200, 500};

    stats->dragon_pos = dragon_pos;
    stats->boss_pos = boss_pos;
    stats->clock = sfClock_create();
    stats->clockb = sfClock_create();
    sfMusic_play(sprites->g_music);
    sfMusic_setLoop(sprites->g_music, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            closewindow(window, event);
        }
        render(window, event, sprites, stats);
    }
}

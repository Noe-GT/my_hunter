/*
** EPITECH PROJECT, 2023
** compute_dragons.c
** File description:
** compute_dragons.c
*/

#include "include/my_hunt.h"

static int reset_dragon(int hp, game_stc *stats)
{
    hp--;
    stats->dragon_pos.y = rand() % 1080;
    stats->dragon_pos.x = -20;
    if (stats->dragon_pos.y > 750) {
        stats->dragon_pos.y = 750;
    }
    return hp;
}

static int compute_boss(game_stc *stats, sprites_stc *sprites)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(stats->clockb);
    seconds = time.microseconds / 1000000.0;
    if (seconds > (0.05))
        stats->boss_pos.x = stats->boss_pos.x + 2;
    if (seconds > 0.25) {
        stats->animb++;
        if (stats->animb == 3) {
            stats->animb = 0;
        }
        sfClock_restart(stats->clockb);
    }
    if (stats->boss_pos.x > 1920) {
        sfSound_play(sprites->fire_sound);
        stats->hp--;
        stats->boss_pos.y = 500;
        stats->boss_pos.x = -200;
    }
}

static void compute_dragon(game_stc *stats, sprites_stc *sprites)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(stats->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > (0.05)) {
        stats->dragon_pos.x = stats->dragon_pos.x + 4 + (2 * stats->game_pace);
    }
    if (seconds > 0.25) {
        stats->anim++;
        if (stats->anim == 3) {
            stats->anim = 0;
        }
        sfClock_restart(stats->clock);
    }
    if (stats->dragon_pos.x > 1920) {
        sfSound_play(sprites->fire_sound);
        stats->hp = reset_dragon(stats->hp, stats);
    }
}

void compute_dragons(game_stc *stats, sprites_stc *sprites)
{
    compute_dragon(stats, sprites);
    if (stats->bossfigth) {
        compute_boss(stats, sprites);
    }
}

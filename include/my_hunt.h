/*
** EPITECH PROJECT, 2023
** C-pool
** File description:
** my
*/

#include "my_include.h"

#ifndef SPRITE_STRUCT
    #define SPRITE_STRUCT

typedef struct sprites_stc {
    sfText *score_text;
    sfText *end_score;
    sfSprite *dragon;
    sfSprite *gdragon;
    sfSprite *boss;
    sfSprite *background;
    sfSprite *end_background;
    sfSprite *rbutton;
    sfSprite *sbutton;
    sfSprite *health;
    sfSprite *guie;
    sfText *game_name;
    sfText *restart_txt;
    sfText *boss_text;
    sfText *bscore_text;
    sfText *best_txt;
    sfMusic *sm_music;
    sfMusic *g_music;
    sfSound *dead_sound;
    sfSound *fire_sound;
    sfMusic *end_music;
} sprites_stc;

#endif /* !SPRITE_STRUCT */

#ifndef GAME_STRUCT
    #define GAME_STRUCT

typedef struct game_stc {
    SFVF dragon_pos;
    SFVF boss_pos;
    int score;
    int bossfigth;
    int anim;
    int anims;
    int animb;
    int game_pace;
    int hp;
    int boss_hp;
    int hightscore;
    sfClock *clock;
    sfClock *clockb;
} game_stc;

#endif /* !GAME_STRUCT */

#ifndef MY_SUH_
    #define MY_SUH_

void game_over(sprites_stc *sprites, SFRW *window, SFE event, game_stc *stats);
int main(int argc, char **argv);
void closewindow(SFRW *window, SFE event);
void set_elements1(void);
void info(void);
void play(SFRW *window, SFE event, sprites_stc *sprites, game_stc *stats);
int draw_score(int score, SFRW *window, sfText *score_text);
void draw_dragons(SFRW *window, game_stc *stats, sprites_stc *sprites);
void compute_dragons(game_stc *stats, sprites_stc *sprites);
void my_hunter(sprites_stc *sprites, game_stc *stats);


#endif /* !MY_SUH_ */

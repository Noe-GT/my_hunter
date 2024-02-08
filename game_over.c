/*
** EPITECH PROJECT, 2023
** game_over.c
** File description:
** game_over.c
*/

#include "include/my_hunt.h"
#include <fcntl.h>

void convert_score(int score, char *score_txt)
{
    char *numbers = "0123456789";

    if (score > 99) {
        score_txt[0] = numbers[score / 100];
        score_txt[1] = numbers[score % 100 / 10];
        score_txt[2] = numbers[score % 10];
    } else if (score > 9) {
        score_txt[0] = '0';
        score_txt[1] = numbers[score / 10];
        score_txt[2] = numbers[score % 10];
    } else {
        score_txt[0] = '0';
        score_txt[1] = '0';
        score_txt[2] = numbers[score % 100];
    }
    score_txt[3] = '\0';
}

int	my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    long long result = 0;

    while (str[i] == '-' || str[i] == '+'){
        if (str[i] == 45){
            sign = sign * -1;
        }
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9'){
            result = result * 10;
            result = result + str[i] - 48;
            i++;
        }
    }
    return (result * sign);
}

static int get_first_line(char *str, char *height_str)
{
    int i = 0;

    while (str[i] != '\n') {
        height_str[i] = str[i];
        i++;
    }
    return i;
}

void hight_score(game_stc *stats, SFRW *window, sprites_stc *sprites)
{
    char *hscore_txt = malloc(sizeof(char) * 4);

    if (stats->hightscore < stats->score) {
        stats->hightscore = stats->score;
        convert_score(stats->score, hscore_txt);
    } else {
        convert_score(stats->hightscore, hscore_txt);
    }
    sfText_setString(sprites->bscore_text, hscore_txt);
    sfRenderWindow_drawText(window, sprites->bscore_text, NULL);
    sfRenderWindow_drawText(window, sprites->best_txt, NULL);
}

void draw_restart(int ranim, SFRW *window, sprites_stc *sprites)
{
    sfIntRect rect;
    sfSprite *btn = sprites->rbutton;

    rect.top = 16 * ranim;
    rect.left = 0;
    rect.width = 32;
    rect.height = 17;
    sfSprite_setTextureRect(btn, rect);
    sfRenderWindow_drawSprite(window, btn, NULL);
}

static int manage_restart(sprites_stc *sprites, SFRW *window, SFE event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    int ranim = 0;

    if (mouse.x > 530 && mouse.x < 1322 && mouse.y > 208 && mouse.y < 700) {
        ranim = 1;
        if (event.type == sfEvtMouseButtonPressed) {
            return 1;
        }
    }
    draw_restart(ranim, window, sprites);
    sfRenderWindow_drawText(window, sprites->restart_txt, NULL);
    return 0;
}

void game_over(sprites_stc *sprites, SFRW *window, SFE event, game_stc *stats)
{
    int restart = 0;
    SFVF text_pos = {700, 30};

    stats->game_pace = 1;
    stats->bossfigth = 0;
    stats->boss_hp = 100;
    stats->boss_pos.x = -300;
    while (sfRenderWindow_isOpen(window) && restart == 0) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            closewindow(window, event);
        }
        sfRenderWindow_drawSprite(window, sprites->end_background, NULL);
        sfRenderWindow_drawSprite(window, sprites->guie, NULL);
        restart = manage_restart(sprites, window, event);
        draw_score(stats->score, window, sprites->end_score);
        hight_score(stats, window, sprites);
        sfRenderWindow_display(window);
    }
    stats->score = 0;
    sfMusic_stop(sprites->end_music);
}

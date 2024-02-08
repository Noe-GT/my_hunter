/*
** EPITECH PROJECT, 2023
** draw_score.c
** File description:
** draw_score.c
*/

#include "include/my_hunt.h"

int draw_score(int score, SFRW *window, sfText *score_text)
{
    char *numbers = "0123456789";
    char score_txt[3];

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
    sfText_setString(score_text, score_txt);
    sfRenderWindow_drawText(window, score_text, NULL);
}

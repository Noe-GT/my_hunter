/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "include/my_hunt.h"

void convert_score2(int score, char *score_txt)
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

int main(int argc, char **argv)
{
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            info();
        }
    } else {
        set_elements1();
    }
    return 0;
}

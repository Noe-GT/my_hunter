/*
** EPITECH PROJECT, 2023
** game.c
** File description:
** game.c
*/

#include "include/my_hunt.h"

void info(void)
{
    write(1, "/////  Dragon Hunter /////\n", 27);
    write(1, "In Dragon Hunter you take the role of a famous hunter", 53);
    write(1, " whose mission is to defend the kingdom against the dragon", 58);
    write(1, " threat.\nShould you fail, your birthplace will", 47);
    write(1, " be engulfed in flames.\n", 24);
    write(1, "//////////\n", 11);
    write(1, "Game made by :\n", 15);
    write(1, "Noe Gebert\n", 11);
}

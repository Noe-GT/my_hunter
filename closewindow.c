/*
** EPITECH PROJECT, 2023
** closeWindow.c
** File description:
** closeWindow.c
*/

#include "include/my_hunt.h"

void closewindow(SFRW *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

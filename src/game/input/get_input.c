/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T08:42:41+01:00 | Author: simon
*/

#include "tetris.h"

bool get_input(char *in, int size)
{
    int idx = 0;
    int c = 1;

    do {
        c = getch();
        if (c == ERR || idx == (size - 1))
            in[idx] = '\0';
        else
            in[idx] = c;
        idx++;
    } while (c != ERR && idx < size);
    if (in[0] != '\0') {
        return true;
    }
    return false;
}

/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-19T09:44:31+01:00 | Author: simon
*/

#include <unistd.h>
#include <term.h>
#include <term.h>
#include <termios.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <sys/ioctl.h>

void canonical_mode_select(bool enable)
{
    static struct termios old;
    static struct termios new;

    if (enable) {
        ioctl(0, TCGETS, &old);
        ioctl(0, TCGETS, &new);

        new.c_lflag &= ~ECHO;
        new.c_lflag &= ~ICANON;
        ioctl(0, TCSETS, &new);
    }
    else if (!enable) {
        ioctl(0, TCSETS, &old);
    }
}

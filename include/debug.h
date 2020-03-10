/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#ifndef DEBUG_H
#define DEBUG_H

typedef struct key_t
{
    int code;
    char *cqfd;
} key_s;

#define PIECE(x) tetris.pieces.pc[x]

#endif
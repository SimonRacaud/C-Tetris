/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** Sort tetriminos array
*/

#include "pieces_t.h"

static int swap_if_greater(tetrimino_t *pc, int i, char *sorted)
{
    tetrimino_t temp;
    int posX = 0;
    int next = (i + 1);

    do {
        if (pc[i].name[posX] > pc[next].name[posX]) {
            temp = pc[i];
            pc[i] = pc[next];
            pc[next] = temp;
            *sorted = 'F';
        } else if (pc[i].name[posX] == pc[next].name[posX]) {
            posX++;
        }
    } while (pc[i].name[posX] >= pc[next].name[posX]);
    return 0;
}

int sort_tetriminos(tetrimino_t *pc, int size)
{
    char is_sorted = 'T';

    do {
        is_sorted = 'T';
        for (int i = 0; i < (size - 1); i++) {
            swap_if_greater(pc, i, &is_sorted);
        }
    } while (is_sorted == 'F');
    return 0;
}

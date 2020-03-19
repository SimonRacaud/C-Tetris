/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include "tetris.h"

/*
 * piece_move(...)
 * return:  true if the piece has moved
 *          false else
 */

void drop_piece(game_t *tetris)
{
    int count = 0;

    while (piece_move(tetris, PIECE_SENS_H)) {
        count++;
    }
    if (count >= 2) {
        piece_move(tetris, PIECE_SENS_H_UP);
    }
}

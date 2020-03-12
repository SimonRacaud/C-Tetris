/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T09:23:55+01:00 | Author: simon
*/

#include "tetris.h"

bool have_str_in_array(char **array, int size, const char *str)
{
    for (int i = 0; i < size; i++) {
        if (my_strcmp(array[i], str) == 0) {
            return true;
        }
    }
    return false;
}

bool have_char_in_string(char c, const char *str)
{
    if (!str)
        return false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            return true;
    }
    return false;
}

int my_get_check_nbr(char *str, int *nbr, const char *ignore)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (have_char_in_string(str[i], ignore))
            continue;
        if ((str[i] < '0' || str[i] > '9') && !(str[i] == '-' && i == 0))
            return EXIT_FAILURE;
    }
    (*nbr) = my_getnbr(str);
    return EXIT_SUCCESS;
}

int get_key_code(char *str, int *nbr)
{
    int len = my_strlen(str);

    if (len != 1)
        return EXIT_FAILURE;
    (*nbr) = (int)str[0];
    return EXIT_SUCCESS;
}

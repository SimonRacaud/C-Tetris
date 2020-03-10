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

char *merge_path_filename(const char *path, const char *filename)
{
    int sizea = my_strlen(path);
    int sizeb = my_strlen(filename);
    char *merge = malloc(sizeof(char) * (sizea + sizeb + 2));

    if (!merge) {
        my_putstr_error("ERORR: malloc : merge_str() \n");
        return NULL;
    }
    if (path[0] != '\0')
        my_strcpy(merge, path);
    if (path[sizea - 1] != '/' && path[0] != '\0') {
        merge[sizea] = '/';
        sizea++;
    }
    if (filename[0] != '\0')
        my_strcpy(&merge[sizea], filename);
    merge[sizea + sizeb] = '\0';
    return merge;
}

char *get_filename_without_ext(const char *filename)
{
    char *ret = NULL;
    int dot_pos = 0;

    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] == '.')
            dot_pos = i;
    }
    ret = malloc(sizeof(char) * (dot_pos + 1));
    if (!ret)
        return NULL;
    my_strncpy(ret, filename, dot_pos + 1);
    ret[dot_pos] = '\0';
    return ret;
}

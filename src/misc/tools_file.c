/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T09:23:55+01:00 | Author: simon
*/

#include "tetris.h"

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
    int dot_pos = -1;

    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] == '.')
            dot_pos = i;
    }
    if (dot_pos == -1) {
        dot_pos = my_strlen(filename) - 1;
    }
    ret = malloc(sizeof(char) * (dot_pos + 1));
    if (!ret)
        return NULL;
    my_strncpy(ret, filename, dot_pos + 1);
    ret[dot_pos] = '\0';
    return ret;
}

bool have_only_correct_char_in_str(const char *str, const char *correct_chars)
{
    for (int i = 0; str[i]; i++) {
        if (!have_char_in_string(str[i], correct_chars))
            return false;
    }
    return true;
}

bool have_right_file_ext(const char *filename, const char *extension)
{
    int dot_pos = -1;

    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] == '.')
            dot_pos = i;
    }
    if (dot_pos == -1) {
        return false;
    } else if (my_strcmp(&filename[dot_pos], extension) == 0) {
        return true;
    }
    return false;
}

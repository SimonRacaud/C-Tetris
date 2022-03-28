/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include <term.h>
#include "tetris.h"
#include "config_t.h"

extern const int NB_KEY;
extern const char *MYTERM;
extern const char *SPECIAL_KEYS[][2];

static char *my_get_term(char **env)
{
    for (int i = 0; env[i]; i++)
        if (my_strncmp(env[i], MYTERM, 5) == 0)
            return my_strdup(env[i] + 5);
    return NULL;
}

static char **get_array(void)
{
    char *tmp;
    char **key = malloc(sizeof(char *) * (NB_KEY + 1));

    if (!key)
        return NULL;
    key[NB_KEY] = '\0';
    for (int i = 0; i < NB_KEY; i++) {
        key[i] = NULL;
        tmp = tigetstr(SPECIAL_KEYS[i][0]);
        if (!tmp)
            continue;
        key[i] = my_strdup(tmp);
        if (!key[i])
            return NULL;
    }
    return key;
}

char **get_special_key(char **env)
{
    int my_errret = 0;
    char *my_term = my_get_term(env);

    if (!my_term)
        return NULL;
    if (setupterm(my_term, 1, &my_errret))
        return NULL;
    free(my_term);
    if (my_errret == -1)
        return 0;
    return get_array();
}

/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** my_itoa
*/

#include <stdlib.h>
#include "libmy.h"

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 5);
    int i = 0;

    for (; nb > 9; nb = nb / 10, i++)
        str[i] = nb % 10 + 48;
    str[i] = nb % 10 + 48;
    str[i + 1] = '\0';
    str = my_revstr(str);
    return (str);
}
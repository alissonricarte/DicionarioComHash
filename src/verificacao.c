#include "../includes/verificacao.h"
#include <stdio.h>
#include <ctype.h>

bool caracteres_permitidos(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)str[i];

        if (!isalpha(c) && c != '-' && c != '\'' && !isspace(c) && c != ',')
        {
            return false;
        }
    }
    return true;
}
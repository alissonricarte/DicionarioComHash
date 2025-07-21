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

void aparar_espacos(char *str) {
    if (str == NULL) return;

    char *inicio = str;
    while (isspace((unsigned char)*inicio)) {
        inicio++;
    }

    if (inicio != str) {
        memmove(str, inicio, strlen(inicio) + 1);
    }

    char *fim = str + strlen(str) - 1;
    while (fim >= str && isspace((unsigned char)*fim)) {
        *fim = '\0';
        fim--;
    }
}
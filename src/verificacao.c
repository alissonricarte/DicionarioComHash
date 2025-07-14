#include "../includes/verificacao.h"
#include<stdio.h>
#include<ctype.h>

void covert_maisculas_minusculas(char* str){

    for(int i = 0; str[i] != '\0'; i++){
        str[i] = tolower ((unsigned char )str[i]);
    }
}

bool caracteres_permitidos(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str[i];

        if (!isalpha(c) && c != '-' && c != '\'' && !isspace(c)) { 
            return false;
        }
    }
    return true;
}
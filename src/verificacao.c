#include "../includes/verificacao.h"
#include<stdio.h>
#include<ctype.h>

void covert_maisculas_minusculas(char* str){

    for(int i = 0; str[i] != '\0'; i++){
        str[i] = tolower ((unsigned char )str[i]);
    }
}
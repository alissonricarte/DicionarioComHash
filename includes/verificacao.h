

#ifndef VERIFICACAO_H
#define VERIFICACAO_H
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


bool caracteres_permitidos(const char *str);
//A função caracteres_permitidos verifica se uma string contém apenas letras, hífens, apóstrofos, vírgulas ou espaços.
// Ela percorre a string, e se encontrar qualquer outro caractere, retorna false.
// Se todos os caracteres forem válidos, retorna true.

void aparar_espacos(char *str);
//A função aparar_espacos remove espaços em branco do início e do fim de uma string.
//Ela avança um ponteiro pelo começo dos espaços e retrocede outro pelo fim,
// substituindo os espaços por um terminador nulo.


#endif
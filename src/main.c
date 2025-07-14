#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../includes/verificacao.h"
#include "../includes/dicionario.h"


int main(){
     dicionario* meu_dicionario = inicializar(4); 
     inserir_palavra(meu_dicionario,"casa","abrigo");

   

    exibir_dic(meu_dicionario);

    remover_palavra(meu_dicionario,"casa");

    char palavra[] = "Ola TuDO beM";
     printf("palavra inserida %s \n", palavra);
    covert_maisculas_minusculas(palavra);
    printf("palavra corriigida: \n %s \n", palavra);

    if(caracteres_permitidos(palavra)){
        printf("valida \n");
    }
    else{
        printf("invalida...");
    }


    return 0;
}
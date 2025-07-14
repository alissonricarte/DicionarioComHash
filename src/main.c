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


    return 0;
}
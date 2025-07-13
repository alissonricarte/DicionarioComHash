#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../includes/verificacao.h"
#include "../includes/z-funcoes.h"


int main(){
     dicionario* meu_dicionario = inicializar(4); 

    if (meu_dicionario != NULL) {
        printf("Dicionario inicializado com sucesso!\n");
        

        inserir_palavra( meu_dicionario,"casa","lar");
         inserir_palavra( meu_dicionario,"casa","abrigo");
    
    } else {
        printf("Falha ao inicializar o dicionario. Encerrando programa.\n");
        return 1; 
    }




    return 0;
}
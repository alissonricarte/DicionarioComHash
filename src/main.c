#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../includes/verificacao.h"
#include "../includes/z-funcoes.h"


int main(){
     dicionario* meu_dicionario = inicializar(2); 

    if (meu_dicionario != NULL) {
        printf("Dicionario inicializado com sucesso!\n");
    
    } else {
        printf("Falha ao inicializar o dicionario. Encerrando programa.\n");
        return 1; 
    }




    return 0;
}
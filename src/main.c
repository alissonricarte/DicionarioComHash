#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../includes/verificacao.h"
#include "../includes/z-funcoes.h"


int main(){
     dicionario* meu_dicionario = inicializar(4); 

    if (meu_dicionario != NULL) {
        

        inserir_palavra( meu_dicionario,"casa","lar");
         inserir_palavra( meu_dicionario,"casa","abrigo");
         const char* palavra_a_buscar1 = "casa";
          palavra* resultado_busca1 = buscar(meu_dicionario, palavra_a_buscar1);
          printf("a palavra %s foi encontrada\n", resultado_busca1->palavra);

         
    
    } else {
        printf("Falha ao inicializar o dicionario. Encerrando programa.\n");
        return 1; 
    }




    return 0;
}
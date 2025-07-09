#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/verificacao.h"
#include "../includes/z-funcoes.h"


dicionario* incializar ( unsigned int tam_inicial){

    dicionario* novo = (dicionario*)malloc(sizeof(dicionario));
        if (novo == NULL){
            printf("Falha na alocação de memória para o dicionário");
                return NULL;
    }
    novo->baldes = (palavra**)malloc(sizeof(palavra*)* tam_inicial);
        if (novo->baldes == NULL){
            printf("Falha ao alocar memória para os baldes do dicionário");
            free(novo);
                return NULL;
        }
    for(unsigned int i = 0; i < tam_inicial; i++){
        novo->baldes [i] = NULL;
    }

    novo->tamanho_atual = tam_inicial;
    novo->numero_elementos = 0; 

            printf("Dicionário inicializado com %u espaços. \n ", tam_inicial);

            return novo;


}
unsigned int calcular_hash(const char* palavra, unsigned int tamanho_tabela) {
    unsigned long hash = 5381; 
    int c;

    
    while ((c = *palavra++)) {
    
        hash = ((hash << 5) + hash) + c; 
    }

    return hash % tamanho_tabela;
}

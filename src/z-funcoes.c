#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/verificacao.h"
#include "../includes/z-funcoes.h"


dicionario* inicializar ( unsigned int tam_inicial){

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


void inserir_palavra(dicionario* dicionario_n, const char* palavra_str, const char* significado_str) {
    if (dicionario_n == NULL || palavra_str == NULL || significado_str == NULL) {
        printf("Erro: Dicionário, palavra ou significado inválido.\n");
        fflush(stdout);
        return;
    }

    unsigned int indice = calcular_hash(palavra_str, dicionario_n->tamanho_atual);
    palavra* atual = dicionario_n->baldes[indice];
    
    
    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra_str) == 0) {

            significado* novo_significado = (significado*)malloc(sizeof(significado));
            if (novo_significado == NULL) {
                printf("Erro: Falha na alocação de memória para o significado.\n");
                fflush(stdout);
                return;
            }
            novo_significado->texto = (char*)(significado_str); 
            if (novo_significado->texto == NULL) {
                printf("Erro: Falha na duplicação da string do significado.\n");
                fflush(stdout);
                free(novo_significado);
                return;
            }
            novo_significado->proximo = atual->significados;
            atual->significados = novo_significado;

            printf("Significado '%s' adicionado à palavra '%s'.\n", significado_str, palavra_str);
            fflush(stdout);
            return;
        }
        atual = atual->proxima; 
    }

    palavra* nova_palavra = (palavra*)malloc(sizeof(palavra));
    if (nova_palavra == NULL) {
        printf("Erro: Falha na alocação de memória para a nova palavra.\n");
        fflush(stdout);
        return;
    }
    nova_palavra->palavra = (char*)(palavra_str);
    if (nova_palavra->palavra == NULL) {
        printf("Erro: Falha na duplicação da string da palavra.\n");
        fflush(stdout);
        free(nova_palavra);
        return;
    }
    nova_palavra->proxima = NULL;

    significado* novo_significado = (significado*)malloc(sizeof(significado));
    if (novo_significado == NULL) {
        printf("Erro: Falha na alocação de memória para o significado da nova palavra.\n");
        fflush(stdout);
        free(nova_palavra->palavra);
        free(nova_palavra);
        return;
    }
    novo_significado->texto = (char*)(significado_str); 
    if (novo_significado->texto == NULL) {
        printf("Erro: Falha na duplicação da string do significado da nova palavra.\n");
        fflush(stdout);
        free(novo_significado);
        free(nova_palavra->palavra);
        free(nova_palavra);
        return;
    }
    novo_significado->proximo = NULL;
    nova_palavra->significados = novo_significado;

    nova_palavra->proxima = dicionario_n->baldes[indice]; 
    dicionario_n->baldes[indice] = nova_palavra;

    dicionario_n->numero_elementos++;

    printf("Palavra '%s' e significado '%s' inseridos no dicionário.\n", palavra_str, significado_str);
    fflush(stdout);
}
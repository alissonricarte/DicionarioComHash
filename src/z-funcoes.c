#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct significado{
    char* texto;
    struct significado* proximo;
} significado;

// struct para os significados de cada palavra.

typedef struct palavra {
    char* palavra;
    significado* significados;
    struct palavra* proxima;

}palavra;

// struct para as listas encadeadas de cada posição da hash,
// contendo as palavras e seus significados.

typedef struct dicionario {
    palavra** baldes;

     unsigned int tamanho_atual;
    unsigned int numero_elementos;

}dicionario;

// struct para o dicionário, 
//baldes é um array de ponteiros, onde cada ponteiro pode ser o
//início de uma lista encadeada (para lidar com colisões).
//Cada elemento dentro dessas listas encadeadas representa uma palavra e seus significados.

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

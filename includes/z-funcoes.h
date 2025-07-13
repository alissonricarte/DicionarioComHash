

#ifndef DICIONARIO_H
#define DICIONARIO_H 

typedef struct significado {
    char* texto;
    struct significado* proximo;
} significado;
// struct para os significados de cada palavra.

typedef struct palavra {
    char* palavra;
    significado* significados;
    struct palavra* proxima;
} palavra;

// struct para as listas encadeadas de cada posição da hash,
// contendo as palavras e seus significados.


typedef struct dicionario {
    palavra** baldes;
    unsigned int tamanho_atual;
    unsigned int numero_elementos;
} dicionario;

// struct para o dicionário, 
//baldes é um array de ponteiros, onde cada ponteiro pode ser o
//início de uma lista encadeada (para lidar com colisões).
//Cada elemento dentro dessas listas encadeadas representa uma palavra e seus significados.

dicionario* inicializar(unsigned int tam_inicial);

unsigned int calcular_hash(const char* palavra, unsigned int tamanho_tabela);

void inserir_palavra(dicionario* dicionario_n, const char* palavra_str, const char* significado_str);



#endif 
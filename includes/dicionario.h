

#ifndef DICIONARIO_H
#define DICIONARIO_H 

typedef struct significado significado;
// struct para os significados de cada palavra.

typedef struct palavra palavra;
// struct para as listas encadeadas de cada posição da hash,
// contendo as palavras e seus significados.

typedef struct dicionario dicionario;
// struct para o dicionário, 
//baldes é um array de ponteiros, onde cada ponteiro pode ser o
//início de uma lista encadeada (para lidar com colisões).
//Cada elemento dentro dessas listas encadeadas representa uma palavra e seus significados.

dicionario* inicializar(unsigned int tam_inicial);

unsigned int calcular_hash(const char* palavra, unsigned int tamanho_tabela);

void inserir_palavra(dicionario* dicionario_n, const char* palavra_str, const char* significado_str);

palavra* buscar(dicionario* dicionario_n, const char* palavra_str);

void exibir_dic(dicionario* dic); 

void remover_palavra(dicionario* dic, const char* palavra_str);

void liberar_dicionario(dicionario* dic);
    

#endif 
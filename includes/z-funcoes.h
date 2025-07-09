

#ifndef DICIONARIO_H
#define DICIONARIO_H 

typedef struct significado {
    char* texto;
    struct significado* proximo;
} significado;

typedef struct palavra {
    char* palavra;
    significado* significados;
    struct palavra* proxima;
} palavra;

typedef struct dicionario {
    palavra** baldes;
    unsigned int tamanho_atual;
    unsigned int numero_elementos;
} dicionario;

dicionario* inicializar(unsigned int tam_inicial);

#endif // DICIONARIO_H
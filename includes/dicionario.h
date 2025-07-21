

#ifndef DICIONARIO_H
#define DICIONARIO_H


typedef struct significado
{
    char *texto;
    struct significado *proximo;
} significado;
// struct para os significados de cada palavra.

typedef struct palavra
{
    char *palavra;
    significado *significados;
    struct palavra *proxima;
} palavra;
// struct para as listas encadeadas de cada posição da hash,
// contendo as palavras e seus significados.


typedef struct dicionario
{
    palavra **baldes;
    unsigned int tamanho_atual;
    unsigned int numero_elementos;
} dicionario;
// struct para o dicionário,
// baldes é um array de ponteiros, onde cada ponteiro pode ser o
// início de uma lista encadeada (para lidar com colisões).
// Cada elemento dentro dessas listas encadeadas representa uma palavra e seus significados.


dicionario *inicializar(unsigned int tam_inicial);
 // função para iniciar o dicionário, aloca memória para dicionario e para o array
// de baldes, inicializa todos os ponteiros de baldes para NULL, além de definir o número 
// de elementos da hash e zerar o contador.

unsigned int calcular_hash(const char *palavra, unsigned int tamanho_tabela);
//Aqui definimos um valor estratégico para usar no cálculo da hash,
// iniciamos um loop para percorrer toda a palavra, usando deslocamento de bits no valor hash,
// somando a seu próprio valor e ao valor de cada caractere da palavra,
// quando termina o loop dividimos o resultado pelo tamanho da tabela e achamos o índice.


void inserir_palavra(dicionario *dicionario_n, const char *palavra_str, const char *significado_str);
//A função inserir_palavra valida a entrada e utiliza a função de calcular hash para achar o balde correto.
// Ela percorre a lista encadeada desse balde. Se a palavra já existe, um novo significado é adicionado usando as listas.
// Caso contrário, a palavra é criada, o significado inserido, e ela é adicionada à lista do balde, com a memória sendo gerenciada.

palavra *buscar(dicionario *dicionario_n, const char *palavra_str);

void exibir_dic(dicionario *dic);

void remover_palavra(dicionario *dic, const char *palavra_str);

void liberar_dicionario(dicionario *dic);

void remover_significado(dicionario* dic, const char* palavra_str, const char* significado_str);

void aparar_espacos(char *str);

#endif


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
//A função buscar utiliza o índice calculado em calcular_hash para iniciar
// um ponteiro para a primeira posição na lista correspondente,
// inicia um loop para percorrer a lista até o fim, fazendo comparações para saber se a palavra buscada está ali.

void exibir_dic(dicionario *dic);
//Aqui primeiro verificamos se o dicionário é nulo ou se está vazio,
// após isso a função utiliza dois loops para percorrer o dicionário,
// um para as palavras e outro aninhado para os significados de cada palavra,
// para printar todos já que cada palavra pode ter mais de 1 significado. 

void remover_palavra(dicionario *dic, const char *palavra_str);
//A função remover_palavra valida a entrada e usa o hash para achar o balde correto.
// Ela percorre a lista de palavras nesse balde com ponteiros "atual" e "anterior".
// Ao encontrar a palavra, ajusta as ligações da lista para remover o nó.
// Em seguida, libera toda a memória da palavra e seus significados, um por um, e diminui a contagem.
// Se a palavra não é encontrada, uma mensagem avisa.

void liberar_dicionario(dicionario *dic);
//A função liberar_dicionario garante que toda a memória usada pelo dicionário seja liberada.
// Ela verifica se o dicionário é válido e, então, percorre cada balde.
// Em cada balde, ela itera por todas as palavras e, para cada uma, libera todos os seus significados.
// Por fim, libera o array de baldes e a própria estrutura do dicionário.

void remover_significado(dicionario* dic, const char* palavra_str, const char* significado_str);
//A função remover_significado valida as entradas e busca a palavra principal no dicionário.
// Se a palavra for encontrada, ela percorre a lista de significados dessa palavra,
// mantendo ponteiros para o significado atual e anterior.
// Ao encontrar o significado específico, ajusta as ligações da lista para removê-lo e libera a memória associada a ele.
// Caso a palavra ou o significado não sejam encontrados, uma mensagem é exibida.

void aparar_espacos(char *str);
//A função aparar_espacos remove espaços em branco do início e do fim de uma string.
//Ela avança um ponteiro pelo começo dos espaços e retrocede outro pelo fim,
// substituindo os espaços por um terminador nulo.

#endif
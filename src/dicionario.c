#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/verificacao.h"
#include "../includes/dicionario.h"

typedef struct significado
{
    char *texto;
    struct significado *proximo;
} significado;

typedef struct palavra
{
    char *palavra;
    significado *significados;
    struct palavra *proxima;
} palavra;

typedef struct dicionario
{
    palavra **baldes;
    unsigned int tamanho_atual;
    unsigned int numero_elementos;
} dicionario;

dicionario *inicializar(unsigned int tam_inicial)
{

    dicionario *novo = (dicionario *)malloc(sizeof(dicionario));
    if (novo == NULL)
    {
        printf("Falha na alocação de memória para o dicionário");
        return NULL;
    }
    novo->baldes = (palavra **)malloc(sizeof(palavra *) * tam_inicial);
    if (novo->baldes == NULL)
    {
        printf("Falha ao alocar memória para os baldes do dicionário");
        free(novo);
        return NULL;
    }
    for (unsigned int i = 0; i < tam_inicial; i++)
    {
        novo->baldes[i] = NULL;
    }

    novo->tamanho_atual = tam_inicial;
    novo->numero_elementos = 0;

    printf("Dicionário inicializado com %u espaços. \n ", tam_inicial);

    return novo;
}
unsigned int calcular_hash(const char *palavra, unsigned int tamanho_tabela)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *palavra++))
    {

        hash = ((hash << 5) + hash) + c;
    }

    return hash % tamanho_tabela;
}

void inserir_palavra(dicionario *dicionario_n, const char *palavra_str, const char *significado_str)
{
    if (dicionario_n == NULL || palavra_str == NULL || significado_str == NULL)
    {
        printf("Erro: Dicionário, palavra ou significado inválido.\n");
        fflush(stdout);
        return;
    }

    unsigned int indice = calcular_hash(palavra_str, dicionario_n->tamanho_atual);
    palavra *atual = dicionario_n->baldes[indice];

    while (atual != NULL)
    {
        if (strcmp(atual->palavra, palavra_str) == 0)
        {
            significado *novo_significado = (significado *)malloc(sizeof(significado));
            if (novo_significado == NULL)
            {
                printf("Erro: Falha na alocação de memória para o significado.\n");
                fflush(stdout);
                return;
            }

            size_t len_significado = strlen(significado_str);
            novo_significado->texto = (char *)malloc(len_significado + 1);
            if (novo_significado->texto == NULL)
            {
                printf("Erro: Falha na duplicação da string do significado.\n");
                fflush(stdout);
                free(novo_significado);
                return;
            }
            strcpy(novo_significado->texto, significado_str);

            novo_significado->proximo = atual->significados;
            atual->significados = novo_significado;

            printf("Significado '%s' adicionado à palavra '%s'.\n", significado_str, palavra_str);
            fflush(stdout);
            return;
        }
        atual = atual->proxima;
    }

    palavra *nova_palavra = (palavra *)malloc(sizeof(palavra));
    if (nova_palavra == NULL)
    {
        printf("Erro: Falha na alocação de memória para a nova palavra.\n");
        fflush(stdout);
        return;
    }

    size_t len_palavra = strlen(palavra_str);
    nova_palavra->palavra = (char *)malloc(len_palavra + 1);
    if (nova_palavra->palavra == NULL)
    {
        printf("Erro: Falha na duplicação da string da palavra.\n");
        fflush(stdout);
        free(nova_palavra);
        return;
    }
    strcpy(nova_palavra->palavra, palavra_str);

    nova_palavra->proxima = NULL;

    significado *novo_significado = (significado *)malloc(sizeof(significado));
    if (novo_significado == NULL)
    {
        printf("Erro: Falha na alocação de memória para o significado da nova palavra.\n");
        fflush(stdout);
        free(nova_palavra->palavra);
        free(nova_palavra);
        return;
    }

    size_t len_novo_significado_str = strlen(significado_str);
    novo_significado->texto = (char *)malloc(len_novo_significado_str + 1);
    if (novo_significado->texto == NULL)
    {
        printf("Erro: Falha na duplicação da string do significado da nova palavra.\n");
        fflush(stdout);
        free(novo_significado);
        free(nova_palavra->palavra);
        free(nova_palavra);
        return;
    }
    strcpy(novo_significado->texto, significado_str);

    novo_significado->proximo = NULL;
    nova_palavra->significados = novo_significado;

    nova_palavra->proxima = dicionario_n->baldes[indice];
    dicionario_n->baldes[indice] = nova_palavra;

    dicionario_n->numero_elementos++;

    printf("Palavra '%s' e significado '%s' inseridos no dicionário.\n", palavra_str, significado_str);
    fflush(stdout);
}

palavra *buscar(dicionario *dicionario_n, const char *palavra_str)
{
    if (dicionario_n == NULL || palavra_str == NULL)
    {
        printf("Falha, dicionário ou palavra de busca inválidos");
        return NULL;
    }
    unsigned int indice = calcular_hash(palavra_str, dicionario_n->tamanho_atual);

    palavra *atual = dicionario_n->baldes[indice];

    while (atual != NULL)
    {
        if (strcmp(atual->palavra, palavra_str) == 0)
        {
            return atual;
            printf("ola");
        }
        atual = atual->proxima;
    }

    return NULL;
}
void exibir_dic(dicionario *dic)
{
    if (dic == NULL)
    {
        printf("Dicionário invalido, fechando...\n");
        return;
    }
    if (dic->numero_elementos == 0)
    {
        printf("O dicionário está vazio... \n Insira novas palavras");
        return;
    }
    for (unsigned i = 0; i < dic->tamanho_atual; i++)
    {
        palavra *atual_palavra = dic->baldes[i];

        while (atual_palavra != NULL)
        {
            printf("-> %s \n ", atual_palavra->palavra);
            significado *atual_significado = atual_palavra->significados;

            while (atual_significado != NULL)
            {
                printf("-%s \n", atual_significado->texto);
                atual_significado = atual_significado->proximo;
            }

            atual_palavra = atual_palavra->proxima;
        }
    }
}

void remover_palavra(dicionario *dic, const char *palavra_str)
{
    if (dic == NULL || palavra_str == NULL)
    {
        printf("Erro, dicionario ou palavra inválidos...\n");
        return;
    }

    unsigned int indice = calcular_hash(palavra_str, dic->tamanho_atual);

    palavra *atual = dic->baldes[indice];
    palavra *anterior = NULL;

    while (atual != NULL)
    {
        if (strcmp(atual->palavra, palavra_str) == 0)
        {
            if (anterior == NULL)
            {
                dic->baldes[indice] = atual->proxima;
            }
            else
            {
                anterior->proxima = atual->proxima;
            }

            significado *sig_atual = atual->significados;
            significado *sig_temp = NULL;

            while (sig_atual != NULL)
            {
                sig_temp = sig_atual;
                sig_atual = sig_atual->proximo;
                free(sig_temp->texto);
                free(sig_temp);
            }

            free(atual->palavra);
            free(atual);

            dic->numero_elementos--;

            printf("Palavra '%s' removida do dicionário.\n", palavra_str);
            return;
        }

        anterior = atual;
        atual = atual->proxima;
    }

    printf("Palavra '%s' nao encontrada no dicionário.\n", palavra_str);
    return;
}

void liberar_dicionario(dicionario *dic)
{
    if (dic == NULL)
    {
        printf("Dicionário inválido ou já liberado.\n");
        return;
    }

    for (unsigned int i = 0; i < dic->tamanho_atual; i++)
    {
        palavra *atual_palavra = dic->baldes[i];
        palavra *temp_palavra = NULL;

        while (atual_palavra != NULL)
        {
            temp_palavra = atual_palavra;
            atual_palavra = atual_palavra->proxima;

            significado *atual_significado = temp_palavra->significados;
            significado *temp_significado = NULL;
            while (atual_significado != NULL)
            {
                temp_significado = atual_significado;
                atual_significado = atual_significado->proximo;
                free(temp_significado->texto);
                free(temp_significado);
            }

            free(temp_palavra->palavra);
            free(temp_palavra);
        }
    }

    free(dic->baldes);
    free(dic);

    printf("Dicionário liberado com sucesso!\n");
}

void remover_significado(dicionario* dic, const char* palavra_str, const char* significado_str) {
    if (dic == NULL || palavra_str == NULL || significado_str == NULL) {
        printf("Erro: Dicionário, palavra ou significado inválido para remover.\n");
        fflush(stdout);
        return;
    }

    palavra* alvo_palavra = buscar(dic, palavra_str); 

    if (alvo_palavra == NULL) {
        printf("Palavra '%s' nao encontrada no dicionario.\n", palavra_str);
        fflush(stdout);
        return;
    }

    significado* atual_sig = alvo_palavra->significados;
    significado* anterior_sig = NULL;

    while (atual_sig != NULL) {
        if (strcmp(atual_sig->texto, significado_str) == 0) {
            if (anterior_sig == NULL) {
                alvo_palavra->significados = atual_sig->proximo;
            } else {
                anterior_sig->proximo = atual_sig->proximo;
            }

            free(atual_sig->texto);
            free(atual_sig);

            printf("Significado '%s' removido da palavra '%s'.\n", significado_str, palavra_str);
            fflush(stdout);
            return;
        }

        anterior_sig = atual_sig;
        atual_sig = atual_sig->proximo;
    }

    printf("Significado '%s' nao encontrado para a palavra '%s'.\n", significado_str, palavra_str);
    fflush(stdout);
}
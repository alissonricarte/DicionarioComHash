#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../includes/dicionario.h"
#include "../includes/verificacao.h"

#define MAX_BUFFER 256

int main() {
    dicionario* meu_dicionario = inicializar(100);

    if (meu_dicionario == NULL) {
        printf("Falha ao inicializar o dicionario. Encerrando programa.\n");
        return 1;
    }
    printf("Dicionario inicializado com sucesso!\n");
    fflush(stdout);

    int opcao;
    char palavra_input[MAX_BUFFER];
    char significado_input[MAX_BUFFER];
    palavra* palavra_encontrada;

    do {
        printf("\n--- DICIONARIO INTERATIVO ---\n");
        printf("1. Inserir Palavra e Significado(s)\n");
        printf("2. Buscar Palavra\n");
        printf("3. Remover Palavra\n");
        printf("4. Remover Significado Especifico\n");
        printf("5. Listar Todas as Palavras\n");
        printf("0. Sair\n");
        printf("-----------------------------\n");
        printf("Escolha uma opcao: ");
        fflush(stdout);

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
            while (getchar() != '\n');
            opcao = -1;
            continue;
        }
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                printf("\n--- INSERIR NOVA PALAVRA/SIGNIFICADO ---\n");
                printf("Digite a palavra: ");
                fgets(palavra_input, MAX_BUFFER, stdin);
                palavra_input[strcspn(palavra_input, "\n")] = 0;

                if (!caracteres_permitidos(palavra_input)) {
                    printf("Erro: A palavra contem caracteres invalidos! (Permitido: letras, '-', '', espacos).\n");
                    break;
                }

                char adicionar_mais_significados;
                do {
                    printf("Digite o significado: ");
                    fgets(significado_input, MAX_BUFFER, stdin);
                    significado_input[strcspn(significado_input, "\n")] = 0;

                    if (!caracteres_permitidos(significado_input)) {
                        printf("Erro: O significado contem caracteres invalidos! Nao sera adicionado.\n");
                    } else {
                        inserir_palavra(meu_dicionario, palavra_input, significado_input);
                    }

                    printf("Deseja adicionar outro significado para '%s'? (s/n): ", palavra_input);
                    fflush(stdout);
                    if (scanf(" %c", &adicionar_mais_significados) != 1) {
                        adicionar_mais_significados = 'n';
                    }
                    while (getchar() != '\n');
                } while (tolower(adicionar_mais_significados) == 's');
                break;

            case 2:
                printf("\n--- BUSCAR PALAVRA ---\n");
                printf("Digite a palavra a buscar: ");
                fgets(palavra_input, MAX_BUFFER, stdin);
                palavra_input[strcspn(palavra_input, "\n")] = 0;

                if (!caracteres_permitidos(palavra_input)) {
                    printf("Erro: Palavra de busca contem caracteres invalidos!\n");
                    break;
                }

                palavra_encontrada = buscar(meu_dicionario, palavra_input);
                if (palavra_encontrada != NULL) {
                    printf("\nPalavra '%s' encontrada! Significados:\n", palavra_encontrada->palavra);
                    significado* sig_atual = palavra_encontrada->significados;
                    while (sig_atual != NULL) {
                        printf("- %s\n", sig_atual->texto);
                        sig_atual = sig_atual->proximo;
                    }
                } else {
                    printf("Palavra '%s' nao encontrada no dicionario.\n", palavra_input);
                }
                break;

            case 3:
                printf("\n--- REMOVER PALAVRA ---\n");
                printf("Digite a palavra a remover: ");
                fgets(palavra_input, MAX_BUFFER, stdin);
                palavra_input[strcspn(palavra_input, "\n")] = 0;

                if (!caracteres_permitidos(palavra_input)) {
                    printf("Erro: Palavra a remover contem caracteres invalidos!\n");
                    break;
                }

                remover_palavra(meu_dicionario, palavra_input);
                break;

            case 4:
                printf("\n--- REMOVER SIGNIFICADO ---\n");
                printf("Digite a palavra do significado a remover: ");
                fgets(palavra_input, MAX_BUFFER, stdin);
                palavra_input[strcspn(palavra_input, "\n")] = 0;

                if (!caracteres_permitidos(palavra_input)) {
                    printf("Erro: Palavra contem caracteres invalidos!\n");
                    break;
                }

                printf("Digite o significado a remover para '%s': ", palavra_input);
                fgets(significado_input, MAX_BUFFER, stdin);
                significado_input[strcspn(significado_input, "\n")] = 0;

                if (!caracteres_permitidos(significado_input)) {
                    printf("Erro: Significado contem caracteres invalidos!\n");
                    break;
                }

                remover_significado(meu_dicionario, palavra_input, significado_input);
                break;

            case 5:
                printf("\n--- LISTA DE PALAVRAS ---\n");
                exibir_dic(meu_dicionario);
                break;

            case 0:
                printf("Saindo do dicionario. Liberando memoria...\n");
                liberar_dicionario(meu_dicionario);
                printf("Memoria liberada com sucesso! Ate mais!\n");
                break;

            default:
                printf("Opcao invalida. Por favor, digite um numero entre 0 e 5.\n");
                break;
        }
        fflush(stdout);
    } while (opcao != 0);

    return 0;
}
# 🧠 Dicionário com Hash – Projeto de Laboratório Estrutura de Dados II (ED2)

## 📍 Universidade
**UFERSA - Universidade Federal Rural do Semi-Árido**  
Curso: **Bacharelado em Tecnologia da Informação**  
Disciplina: **Laboratório Estrutura de Dados II (ED2)**  
Professor: **Kennedy Reurison Lopes**

---

## 🎯 Descrição do Projeto
Este projeto tem como objetivo aplicar o conceito de **tabelas hash** no desenvolvimento de um sistema de dicionário textual, no qual o usuário pode:

- Inserir palavras e seus significados;
- Buscar palavras cadastradas;
- Remover palavras;
- Salvar e carregar o dicionário de um arquivo externo;
- Associar múltiplos significados para a mesma palavra.

A implementação foi realizada na linguagem **C**, com foco em eficiência, modularidade e uso prático de estruturas de dados.

---

## 👨‍💻 Integrantes e Funções

| Nome                                    | Função          |
|-----------------------------------------|-----------------|
| Alisson Lima Ricarte                    | GitMaster       |
| Francisco Daniel Costa de Souza         | Codificador     |
| Marcelo Henrique de Lima Marques        | Apresentador    |
| Mateus Gomes Pinheiro                   | Redator         |

---

## 🧠 Estrutura de Dados Utilizada
- **Tabela Hash com tratamento de colisões por encadeamento separado (listas encadeadas)**
- Cada posição da tabela armazena uma lista de palavras;
- Cada palavra pode conter uma lista de significados associados.

---

## 🛠️ Como compilar, executar e utilizar o programa

📌 *(Complete esta seção com os comandos reais após concluir o código)*

```bash
gcc main.c -o dicionario
./dicionario

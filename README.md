# 🧠 Dicionário com Hash – Projeto de Laboratório Estrutura de Dados II (ED2)

## 📍 Universidade
**UFERSA - Universidade Federal Rural do Semi-Árido**  
**Curso**: Bacharelado em Tecnologia da Informação  
**Disciplina**: Laboratório Estrutura de Dados II (ED2)  
**Professor**: Kennedy Reurison Lopes

---

## 🎯 Descrição do Projeto

Este projeto implementa um dicionário eficiente utilizando **tabela hash** com as seguintes características:

- 🔑 **Função hash DJB2** para distribuição uniforme;
- 🔁 **Tratamento de colisões** por encadeamento separado (listas ligadas);
- 🧭 **Interface intuitiva via linha de comando**.

### Funcionalidades principais:

- 🆕 Inserção de palavras com múltiplos significados;
- 🔍 Busca rápida com complexidade **O(1)** em casos ideais;
- 🗑️ Remoção de palavras ou significados específicos;
- 💾 Salvamento automático do dicionário;
- 📜 Listagem completa organizada.

---
### 🧾 Comandos disponíveis

```
1 - Inserir Palavra e Significado(s)
2 - Buscar Palavra
3 - Remover Palavra
4 - Remover Significado Especifico
5 - Listar Todas as Palavras
0 - Sair
```

---
### Tecnologia Utilizada:
<div>
    <img width="50" height="26" alt="C" src="https://img.shields.io/badge/C-4169E1?style=for-the-badge&logo=c&logoColor=white"/>
</div>

---

## 👨‍💻 Integrantes e Funções

| Nome                               | Função        | Contribuição                            |
|------------------------------------|---------------|------------------------------------------|
| Alisson Lima Ricarte              | GitMaster     | Gerenciamento do repositório e documentação |
| Francisco Daniel Costa de Souza   | Codificador   | Implementação da tabela hash e funções principais |
| Marcelo Henrique de Lima Marques  | Apresentador  | Testes e validação do sistema           |
| Mateus Gomes Pinheiro             | Redator       | Documentação e relatórios               |

---

## 🏗️ Arquitetura do Sistema

```
dicionario-hash/
├── includes/
│   ├── dicionario.h        # Definições da estrutura hash
│   └── verificacao.h       # Funções de validação
├── src/
│   ├── dicionario.c        # Implementação da lógica do dicionário
│   ├── verificacao.c       # Validação de entradas
│   └── persistencia.c      # Manipulação de arquivos
├── main.c                  # Interface principal com o usuário
└── Makefile                # Automação de compilação
```

---

## 🛠️ Instalação e Uso

### ✅ Pré-requisitos

- Compilador **GCC**
- Sistema **Linux/Unix** ou **Windows com MinGW**
- Utilitário **Make** (opcional)

### 📦 Compilação

```bash
git clone https://github.com/alissonricarte/DicionarioComHash
cd "caminho/completo/para/o/diretorio/do/projeto"
gcc src/main.c src/dicionario.c src/verificacao.c -Iincludes -o main.exe
```

### ▶️ Execução

```bash
.\main.exe
```
<h2 id="colab" align="center" style="font-weight: bold; font-size: 2rem">Colaboradores</h2>
  <div align="center">
    <table>
      <tr>
        <td align="center">
          <a href="#">
            <img src="https://avatars.githubusercontent.com/u/144806270?v=4" width="100px;" alt="alisson"/><br>
            <sub>
              <a href="https://github.com/alissonricarte"><b>Alisson Ricarte</b></a>
            </sub>
          </a>
        </td>
        <td align="center">
          <a href="#">
            <img src="https://avatars.githubusercontent.com/u/147107207?v=4" width="100px;" alt="daniel"/><br>
            <sub>
              <a href="https://github.com/daniel1234costa"><b>Daniel Costa</b></a>
            </sub>
          </a>
        </td>
        <td align="center">
          <a href="#">
            <img src="https://avatars.githubusercontent.com/u/156232385?v=4" width="100px;" alt="mateus"/><br>
            <sub>
              <a href="https://github.com/mateussspinheiro"><b>Mateus Pinheiro</b></a>
            </sub>
          </a>
        </td>
        <td align="center">
          <a href="#">
            <img src="https://avatars.githubusercontent.com/u/185148834?v=4" width="100px;" alt="marcelo"/><br>
            <sub>
              <a href="https://github.com/MarceloHmarques"><b>Marcelo Marques</b></a>
            </sub>
          </a>
        </td>
    </table>
   <span style="font-weight: bold;">Equipe DicionárioHash - Obrigado por utilizar nosso sistema!</span>
  </div>
</div>

<img width=100% src="https://capsule-render.vercel.app/api?type=waving&height=110&color=F9F9F4&section=footer&reversal=false"/>

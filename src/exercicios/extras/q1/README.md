# Questão 1 — Cadastro de Livros

Este diretório contém um sistema simples em C para cadastro de livros, desenvolvido para fins didáticos.

## Descrição

O programa permite cadastrar **3 livros**, cada um com:
- **Título** (até 100 caracteres)
- **Autor** (até 50 caracteres)
- **Ano de publicação**

O sistema garante que o usuário não insira mais caracteres do que o permitido para cada campo, utilizando uma função utilitária (`read_line`) para leitura segura das entradas.

Após o cadastro, o programa exibe as informações dos livros registrados.

## Estrutura dos Arquivos

- `livros.c`: Código principal do programa.
- `utils/readline.c` e `utils/readline.h`: Função utilitária para leitura segura de strings.
- `makefile`: Script para compilar e limpar o projeto.
- `livros`: Executável gerado após a compilação.

## Como compilar e executar

O projeto utiliza um Makefile para facilitar a compilação. Para compilar e rodar o programa:

1. **Abra o terminal e navegue até o diretório `q1`:**
   ```sh
   cd "Novos Exercicios/q1"
   ```

2. **Compile o programa:**
   ```sh
   make
   ```
   Isso irá gerar o executável chamado `livros`.

3. **Execute o programa:**
   ```sh
   ./livros
   ```

4. **Para limpar os arquivos gerados (executável e arquivos `.o`):**
   ```sh
   make clean
   ```

## Explicação do Makefile

- **Variáveis principais:**
  - `CC`: Compilador utilizado (gcc)
  - `CFLAGS`: Opções de compilação (`-std=c99 -Wall -O2`)
  - `OBJ`: Arquivos objeto necessários (`livros.o utils/readline.o`)

- **Alvos:**
  - `livros`: Compila o programa principal a partir dos arquivos objeto.
  - `%.o: %.c`: Regra para compilar qualquer arquivo `.c` em `.o`.
  - `clean`: Remove arquivos objeto e o executável.

## Observações

- O programa utiliza `setlocale` para suportar acentuação em português.
- A função `read_line` garante que não haja estouro de buffer ao ler strings do usuário.

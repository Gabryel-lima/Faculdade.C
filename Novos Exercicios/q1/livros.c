/* Uma livraria deseja desenvolver um sistema para cadastrar livros. Cada livro possui um título, um autor e o ano de publicação. No entanto, 
o sistema deve garantir que os usuários não insiram mais caracteres do que os permitidos nos campos de título e autor (100 e 50 caracteres, 
respectivamente). Implemente o sistema que permita o cadastro de 3 livros e garanta que as entradas do usuário não excedam os limites 
permitidos. Em seguida, exiba as informações dos livros cadastrados. */

/*
 * Sistema simples de cadastro de livros
 * — 3 registros
 * — Título: 100 caracteres máx.   (buffer de 101 ⇒ 100 + '\0')
 * — Autor :  50 caracteres máx.   (buffer de 51  ⇒  50 + '\0')
 *
 * Compilar:  gcc -std=c99 -Wall -Wextra -O2 livros.c -o livros
 */

#include <stdio.h> // header padrão de input e output
#include <locale.h> // hearder que define um conjunto de convenções culturais usadas para formatação de texto, números, datas, ordenação alfabética, etc.
#include <string.h> // funções para manipulações de strings de C em Unix/linux

#define MAX_LIVROS 3
#define MAX_TITULO 100
#define MAX_AUTOR 50

typedef struct livros {
    char titulo[MAX_TITULO + 1]; /* +1 para o terminador null*/
    char autor[MAX_AUTOR + 1];
    int ano;
} Livros;

/*----------------------------------------------------------*/
/* Função utilitária: lê uma linha com segurança,           *
 * removendo o '\n' inserido por fgets, se existir.         */
static void read_line(char *dest, size_t lenght) {
    if(fgets(dest, (int)lenght, stdin) == NULL) {
        dest[0] = '\0'; /* EOF inesperado ⟶ string vazia */
        return;
    }
    dest[strcspn(dest, "\n")] = '\0'; 
}

/*----------------------------------------------------------*/

int main(void) {

    Livros livros[MAX_LIVROS] = {0};

    puts("+++ Cadastro dos Livros +++");
    for (int i = 0; i < MAX_LIVROS; i++) {
        printf("\nLivro %d%d\n", i + 1, MAX_LIVROS); // %d%d = (double, double)

        printf("Titulo (até %d caracteres): ", MAX_TITULO);
        read_line(livros[i].titulo, sizeof livros[i].titulo);

        printf("Autor (até %d caracteres): ", MAX_AUTOR);
        read_line(livros[i].autor, sizeof livros[i].autor);

        printf("Ano de publicação: ");
        while (scanf("%d", &livros[i].ano) != 1) {
            while (getchar() != '\n');  /* limpa a entrada inválida */
            fputs(" Entrada inválida. Digite o ano novamente: ", stdout);
        }
        while (getchar() != '\n');  /* descarta o '\n' pendente */
    }

    /*----------------------------------------------------------*/
    puts("\n=== Livros cadastrados ===");
    for (int i = 0; i < MAX_LIVROS; i++) {
        printf("[%d]\n", i + 1);
        printf("Título : %s\n", livros[i].titulo);
        printf("Autor  : %s\n", livros[i].autor);
        printf("Ano    : %d\n\n", livros[i].ano);
    }
    return 0;
}



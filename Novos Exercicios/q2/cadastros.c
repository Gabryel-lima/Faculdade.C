/* Uma empresa deseja criar um sistema para cadastrar funcionários. Cada funcionário tem um nome, um cargo e um salário. O nome pode 
ter  no  máximo  50  caracteres  e  o  cargo  pode  ter  até  30  caracteres.  Após  cadastrar  5  funcionários,  o  sistema  deve  verificar  se  há  algum 
funcionário com o mesmo cargo e, se houver, exibir os detalhes desses funcionários. */

/*
 * Sistemas simples de cadastro de funcionários
 * 
 * 
*/

#include <stdio.h> // hearder de input e output
#include <locale.h> // hearder de conjunto de convenções semânticas
#include <string.h> // funções para manipulação de strings
#include "cadastros.h" // my hearder

//#include "utils/readline.h" // lê uma string com segurança

#define MAX_FUNCIONARIOS 4
#define MAX_NOME_STR 50
#define MAX_CARGO 30

/* O typedef é legal, pois você não precisa declarar 
 * explicitamente struct.
*/
typedef struct cadastros {
    int funcionarios[MAX_FUNCIONARIOS + 1];
    char nome[MAX_NOME_STR + 1];
    char cargo[MAX_CARGO + 1];
    double salario;
} Cadastros; // alias

void cadastrarFuncionario(int opcao) {
    for (int i = 0; i <= MAX_FUNCIONARIOS; i++) {
        printf("\nVocê selecionou a opção cadastro, forneça um nome: ");
        scanf(" %i", &opcao);
    }
}

void totalFuncionario() {
    printf("\n(%i) funcionários", MAX_FUNCIONARIOS);
}

int main(void) {
    // Salva guarda para o setlocale()
    if (!setlocale(LC_ALL, "pt_BR.UTF-8")) {
        fputs("Locale pt_BR.UTF-8 indisponível\n", stderr);
    }

    // Declaração da struct
    Cadastros cadastros[MAX_FUNCIONARIOS] = {0}; // idx em 0
    int opcao = 0;

    // O do while serve bem neste caso com o switch
    do {
        printf("\n--- Menu de opções --");
        printf("\n[1] Cadastrar funcionários");     
        printf("\n[2] Total de funcionários");
        printf("\n[3] Ocupação");
        printf("\n[4] Sair ");
        printf("\nDigite a opção desejada: ");
        scanf(" %i", &opcao);
        switch (opcao) {
            case 1:
                cadastrarFuncionario(opcao);
                break;
            case 2:
                totalFuncionario();
                break;
            default:
                printf("Opção inválida! ");
                break;
        }
    } while (opcao != 4); // Caso for diferente de 4 continua true.

    return 0;
}


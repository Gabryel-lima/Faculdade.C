
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

#define MAX_NOME 99

struct Estudante {
    char nome[MAX_NOME];
    int ru;
};

void ValidaImpar(struct Estudante *ref) {
    setlocale(LC_ALL, "Portuguese");
    if (ref->ru % 2 == 0) {
        wprintf(L"\n->O RU é par!");
    }
    else {
        wprintf(L"\n->O RU é impar!");
    }
}

void ValidaNome(struct Estudante *ref) {
    printf("\n->Escreva seu nome: ");
    fgets((ref)->nome, MAX_NOME, stdin);
}

void ValidaRu(struct Estudante *ref) {
    printf("->Digite seu RU: ");
    scanf("%d", &(ref)->ru);
}

void InverteNome(struct Estudante *ref) {
    size_t length = strlen((ref)->nome);
    if (length > 0 && (ref)->nome[length - 1] == '\n') {
        (ref)->nome[length - 1] = '\0';
    }
    strrev((ref)->nome);
    printf("\n->Nome invertido: %s\n", (ref)->nome);
    printf("\nPressione qualquer tecla para finalizar..."); getch();
}

void ConstroiMenu() {
    for (size_t i = 0; i < 30; i++) {
        printf("*");
    }
    printf("\n");
    printf("*");
    printf("         ");
    printf("Bem vindo!");
    printf("         ");
    printf("*");
    printf("\n");
    for (size_t j = 0; j < 30; j++) {
        printf("*");
    }
}

void Run() {

    struct Estudante referencia;

    ConstroiMenu();
    ValidaNome(&referencia);
    ValidaRu(&referencia);
    ValidaImpar(&referencia);
    InverteNome(&referencia);
}

int main() {
    Run();

    return 0;
}

/**
 * Inverte o nome de um estudante e imprime o resultado.
 *
 * Esta função inverte o nome armazenado na estrutura Estudante referenciada
 * por 'ref' e imprime o nome invertido no console.
 *
 * //@param ref Um ponteiro para a estrutura Estudante contendo o nome a ser invertido.
 */
//void InverteNome(struct Estudante *ref) {
    // Calcula o comprimento atual da string nome.
    //size_t length = strlen(ref->nome);
    
    // Verifica se o último caractere é um '\n' (caractere de nova linha).
    //if (length > 0 && ref->nome[length - 1] == '\n') {
        // Se for, substitui o '\n' por '\0' (caractere nulo) para remover o '\n'.
        //ref->nome[length - 1] = '\0';
    //}
    
    // Chama a função strrev para inverter a string nome.
    //strrev(ref->nome);
    
    // Imprime o nome invertido no console.
    //printf("\n->Nome invertido: %s\n", ref->nome);
//}

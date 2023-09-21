
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX_NOME 100

struct Estudante {
    char nome[MAX_NOME];
    int ru;
};

void ValidaImpar(struct Estudante *referencia) {
    setlocale(LC_ALL, "Portuguese");

    if (referencia->ru % 2 == 0) {
        wprintf(L"\n->O RU é par!");
    }
    else {
        wprintf(L"\n->O RU é impar!");
    }
}

void ValidaNome(struct Estudante *referencia) {
    printf("->Escreva seu nome: ");
    scanf("%s", &referencia->nome);
}

void ValidaRu(struct Estudante *referencia) {
    printf("->Digite seu RU: ");
    scanf("%d", &referencia->ru);
}

void InverteNome(struct Estudante *referencia) {
    #include <string.h>
    strrev(referencia->nome);
    printf("\n->Nome invertido: %s\n", referencia->nome);
}

void ConstroiMenu() {
    printf("******************************");
    printf("\n");
    printf("*");
    printf("         ");
    printf("Bem vindo!");
    printf("         ");
    printf("*");
    printf("\n");
    printf("******************************\n");
}

int main() {
    struct Estudante referencia;

    ConstroiMenu();
    ValidaNome(&referencia);
    ValidaRu(&referencia);
    ValidaImpar(&referencia);
    InverteNome(&referencia);

    return 0;
}
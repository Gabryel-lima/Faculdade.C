
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

struct Leitura {
    int tamanho, indice;
    double leituras[100];
    double soma;
};

void ConstroiMenu() {
    printf("\n");
    for (size_t i = 0; i < 30; i++) {
        printf("~");
    }
    printf("\n");
    printf("*");
    printf("         ");
    printf("Bem vindo!");
    printf("         ");
    printf("*");
    printf("\n");
    for (size_t j = 0; j < 30; j++) {
        printf("~");
    }
}

void Init(struct Leitura *ref) {
    printf("\n\nQuantas leituras deseja analisar? ");
    scanf("%d", &(ref)->tamanho);
    printf("\n");
}

void Incremento(struct Leitura *ref) {
    for ((ref)->indice = 0; (ref)->indice < (ref)->tamanho; (ref)->indice++) {
    printf("->Informe a leitura %d : ", (ref)->indice + 1);
    scanf("%lf", &(ref)->leituras[(ref)->indice]);
    }
}

double somaQuadrados(double leituras[], int tamanho, int indice) {
    if (indice == tamanho - 1) {
        return leituras[indice] * leituras[indice];
    } else {
        return leituras[indice] * leituras[indice] + somaQuadrados(leituras, tamanho, indice + 1);
    }
}

void Finalizando(struct Leitura *ref) {
    (ref)->soma = somaQuadrados((ref)->leituras, (ref)->tamanho, 0);
    wprintf(L"\nO valor RMS do sinal é: %.2lf\n", sqrt((ref)->soma / (ref)->tamanho));
}

void Run() {

    setlocale(LC_ALL, "Portuguese");

    struct Leitura Leitura;

    ConstroiMenu();
    Init(&Leitura);
    Incremento(&Leitura);
    Finalizando(&Leitura);

}

int main() {
    Run();

    return 0;
}

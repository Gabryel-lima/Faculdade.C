
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define NUM_MAX 99

struct Registro {
    char ru[NUM_MAX];
    int num_digits;
    int produto;
};

void ConstroiMenu() {
    for (size_t i = 0; i < 30; i++) {
        printf("-");
    }
    printf("\n");
    printf("*");
    printf("         ");
    printf("Bem vindo!");
    printf("         ");
    printf("*");
    printf("\n");
    for (size_t j = 0; j < 30; j++) {
        printf("-");
    }
}

void ValidaRu(struct Registro *ref) {
    printf("\n->Digite seu RU: ");
    scanf("%s", &ref->ru[NUM_MAX]);

    while (ref->ru[ref->num_digits] != '\0') {
        ref->num_digits++;
    }
}

void VetorRU(struct Registro *ref) {
    int *ru_digits = malloc(ref->num_digits * sizeof(int));
    
    for (int i = 0; i < ref->num_digits; i++) {
        ref->ru[i] = ru_digits[i] - '0'; 
    }
}

void ProdutoDoVetor(struct Registro *ref) {
    ref->produto = 1;
    for (int i = 0; i < ref->num_digits; i++) {
        ref->produto *= ref->ru[i];
    }
}

void Resultado(struct Registro *ref) {
    printf("Vetor de dígitos do RU: ");
    for (int i = 0; i < ref->num_digits; i++) {
        printf("%c ", ref->ru[i]);
    }
    printf("\nProduto dos dígitos: %d\n", ref->produto);
}

void Run() {

    struct Registro referencia;

    ConstroiMenu();
    ValidaRu(&referencia);
    VetorRU(&referencia);
    ProdutoDoVetor(&referencia);
    Resultado(&referencia);
}

int main() {
    Run();

    return 0;
}
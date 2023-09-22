
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Registro {
    char ru_string[100];
    int num_digitos;
    int *ru_digitos;
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

void Ru(struct Registro *ref) {
    printf("\nDigite o seu RU: "); 
    scanf("%s", ref->ru_string);
}

void QuantidadeDeDigitos(struct Registro *ref) {
    ref->num_digitos = 0;
    while (ref->ru_string[ref->num_digitos] != '\0') {
        ref->num_digitos++;
    }
}

void Incremento(struct Registro *ref) {
    ref->ru_digitos = malloc(ref->num_digitos * sizeof(int));

    for (int i = 0; i < ref->num_digitos; i++) {
        ref->ru_digitos[i] = ref->ru_string[i] - '0'; 
    }
    ref->produto = 1;
    for (int j = 0; j < ref->num_digitos; j++) {
        ref->produto *= ref->ru_digitos[j];
    }
}

void Resultado(struct Registro *ref) {
    printf("\nVetor de dígitos do RU: ");
    for (int i = 0; i < ref->num_digitos; i++) {
        printf("[%d]", ref->ru_digitos[i]);
    }
    printf("\nProduto dos dígitos: %d\n", ref->produto);
    free(ref->ru_digitos);
}

void Run() {

    struct Registro referencia;

    ConstroiMenu();
    Ru(&referencia);
    QuantidadeDeDigitos(&referencia);
    Incremento(&referencia);
    Resultado(&referencia);
}

int main() {
    Run();

    return 0;
}

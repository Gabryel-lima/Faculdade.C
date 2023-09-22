#include <stdio.h>
#include <stdlib.h>

int main() {
    // Solicitar ao usuário que insira o RU
    printf("Digite o seu RU: ");
    char ru_string[100]; // Assumindo que o RU pode ter até 100 dígitos
    scanf("%s", ru_string);

    // Calcular o número de dígitos no RU
    int num_digitos = 0;
    while (ru_string[num_digitos] != '\0') {
        num_digitos++;
    }

    // Criar um vetor com o mesmo número de dígitos do RU
    int *ru_digitos = (int *)malloc(num_digitos * sizeof(int));

    // Preencher o vetor com os dígitos do RU
    for (int i = 0; i < num_digitos; i++) {
        ru_digitos[i] = ru_string[i] - '0'; // Converter de caractere para inteiro
    }

    // Calcular o produto de todos os números no vetor
    int produto = 1;
    for (int i = 0; i < num_digitos; i++) {
        produto *= ru_digitos[i];
    }

    // Imprimir o resultado
    printf("Vetor de dígitos do RU: ");
    for (int i = 0; i < num_digitos; i++) {
        printf("%d ", ru_digitos[i]);
    }
    printf("\nProduto dos dígitos: %d\n", produto);

    // Liberar a memória alocada para o vetor
    free(ru_digitos);

    return 0;
}

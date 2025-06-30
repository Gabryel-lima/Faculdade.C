
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int inteiro = 1;
    char caractere = 'A';
    double duplo = 1.0;
    float flutuante = 0.0;
    const int constante = 100;
    
    wprintf(L"\nO valor representado de um int é: %d", inteiro);
    wprintf(L"\nO valor representado de um char é: %c", caractere);
    wprintf(L"\nO valor representado de um double é: %f", duplo);
    wprintf(L"\nO valor representado de um float é: %f", flutuante);
    wprintf(L"\nO valor representado de um const int é: %d", constante);
    printf("\n");

    return 0;
}

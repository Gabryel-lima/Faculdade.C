
#include <stdio.h>
#include <locale.h>

int print() {
    setlocale(LC_ALL, "Portuguese");
    //wprintf(L"");

    return 0;
}; //print;

struct Estudante {
    char nome[100];
    int ru; 
} referencia;

int ValidaNome() {
    printf("\n->Escreva seu nome: ");
    scanf("%s", referencia.nome);

    return 0;
};

int ValidaRu() {

    return 0;
};

int Constroi_Menu() {
    printf("******************************");
    printf("\n");
    printf("*");
    printf("         ");
    printf("Bem vindo!");
    printf("         ");
    printf("*");
    printf("\n");
    printf("******************************");

    return 0;
};

int main() {
    Constroi_Menu();
    ValidaNome();

    return 0;
}

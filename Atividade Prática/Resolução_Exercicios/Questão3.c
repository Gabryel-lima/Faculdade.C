
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define M_PI 3.14159265358979323846

struct entrada {
    float inp;
};

struct area {
    float are;
};

struct perimetro {
    float per;
    struct area *area;
};

void ConstroiMenu() {
    for (size_t i = 0; i < 30; i++) {
        printf(">");
    }
    printf("\n");
    printf("*");
    printf("         ");
    printf("Bem vindo!");
    printf("         ");
    printf("*");
    printf("\n");
    for (size_t j = 0; j < 30; j++) {
        printf("<");
    }
}

void ValorLado(struct entrada *ref) {
    printf("\nInsira o valor: ");
    scanf("%f", &(ref)->inp);
}

void Calc_penta(float l, struct area *area, struct perimetro *perimetro) {
    area->are = (5 * pow(l, 2)) / (4 * tan(M_PI / 5));
    (perimetro)->per = 5 * l;

    wprintf(L"\nÁrea: %.2lf\n", (area)->are);
    wprintf(L"Perímetro: %2.lf\n", (perimetro)->per);
    free((perimetro)->area);
}

void Run() {

    setlocale(LC_ALL, "Portuguese");

    struct entrada entrada;
    struct area area;
    struct perimetro perimetro;

    ConstroiMenu();
    ValorLado(&entrada);
    perimetro.area = malloc(sizeof(struct area));
    Calc_penta((entrada).inp, &area, &perimetro);
}

int main() {
    Run();

    return 0;
}

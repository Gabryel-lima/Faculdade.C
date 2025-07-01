#include <stdio.h> // Hearder de entrada e saída.
#include <math.h> // header de funções matemáticas.
#include <locale.h> // hearder que define um conjunto de convenções culturais usadas para formatação de texto, números, datas, ordenação alfabética, etc.

#define TRANSVERSAL(b, h) (b) * (h) // Macro para o cálculo da área da seção transversal.
#define INERCIA(b, h) ((b) * (pow(h, 3)) / 12) // Macro para o cálculo do momento de inércia.

int main(void) {
    /*
    Declaração de variáveis:
    - largura: largura da viga.
    - altura: altura da viga.
    - transversal: área da seção transversal.
    - inercia: momento de inércia.
    */

    // Salva guarda para o setlocale() para garantir que o programa funcione corretamente em qualquer sistema operacional.
    if (!setlocale(LC_ALL, "pt_BR.UTF-8")) {
        fputs("Locale pt_BR.UTF-8 indisponivel\n", stderr);
    }

    printf("\n+++ Questão 1 +++\n");

    int largura, altura; // Variáveis para armazenar a largura e altura da viga.
    float transversal, inercia; // Variáveis para armazenar a área da seção transversal e o momento de inércia.

    // Apenas garantindo que a entrada seja um número inteiro.
    printf("\nDigite a largura (cm): "); // Solicita a largura da viga.
    if (scanf("%i", &largura) != 1) {
        fprintf(stderr, "Erro ao ler a largura.\n");
        return 1;
    }

    // Apenas garantindo que a entrada seja um número inteiro.
    printf("Digite a altura (cm): "); // Solicita a altura da viga.
    if (scanf("%i", &altura) != 1) {
        fprintf(stderr, "Erro ao ler a altura.\n");
        return 1;
    }

    printf("\n+++ Calculando a área da seção transversal +++"); // Exibe uma mensagem indicando que o programa está calculando a área da seção transversal.
                
    transversal = TRANSVERSAL(largura, altura); // Calcula a área da seção transversal.
    inercia = INERCIA(largura, altura); // Calcula o momento de inércia.

    printf("\n» Área = %.2f cm²", transversal); // Exibe a área da seção transversal.
    printf("\n» Momento de inercia = %.2f cm⁴", inercia); // Exibe o momento de inércia.
    
    if(transversal >= 100) { // Verifica se a área da seção transversal é maior ou igual a 100 cm².
        printf("\n» A viga está apta para carga básica (A >= 100 cm²).\n\n"); // Exibe uma mensagem indicando que a viga está apta para carga básica.
    }
    else { // Se a área da seção transversal não for maior ou igual a 100 cm².
        printf("\n» A viga não está apta\n\n");
    }

    return 0;
}

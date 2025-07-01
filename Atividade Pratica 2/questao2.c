#include <stdio.h> // Hearder de entrada e saída.
#include <stdlib.h> // Header de funções para alocação de memória.
#include <float.h> // Header de funções para operações com números de ponto flutuante.
#include <locale.h> // hearder que define um conjunto de convenções culturais usadas para formatação de texto, números, datas, ordenação alfabética, etc.

static inline float minf(float a, float b) {return a < b ? a : b; }; // Função para encontrar o menor valor entre dois números de ponto flutuante.
static inline float maxf(float a, float b) {return a > b ? a : b; }; // Função para encontrar o maior valor entre dois números de ponto flutuante.

void estatisticas(const float *v, size_t n, float *media, float *minimo, float *maximo) {
    /*
    Função para calcular as estatísticas de um vetor de números de ponto flutuante.
    - v: vetor de números de ponto flutuante.
    - n: tamanho do vetor.
    - media: ponteiro para a variável que armazenará a média dos números.
    - minimo: ponteiro para a variável que armazenará o menor número.
    - maximo: ponteiro para a variável que armazenará o maior número.
    */
    double soma = 0.0; // Variável para armazenar a soma dos números.
    float minv = v[0], maxv = v[0];

    for (size_t i = 0; i < n; ++i) {
        soma += v[i];
        minv = minf(minv, v[i]);
        maxv = maxf(maxv, v[i]); 
    }
    *media = (float)(soma / n);
    *minimo = minv;
    *maximo = maxv;
}

int main(void) {
    /*
    Função principal do programa.
    - setlocale: define o locale do programa para garantir que o programa funcione corretamente em qualquer sistema operacional.
    - printf: exibe uma mensagem de boas-vindas.
    - scanf: lê o número de leituras.
    - malloc: aloca memória para o vetor de leituras.
    - free: libera a memória alocada para o vetor de leituras.
    */

    // Salva guarda para o setlocale() para garantir que o programa funcione corretamente em qualquer sistema operacional.
    if (!setlocale(LC_ALL, "pt_BR.UTF-8")) {
        fputs("Locale pt_BR.UTF-8 indisponivel\n", stderr);
    }

    printf("\n+++ Questão 2 +++\n");

    size_t n;
    printf("\nQuantas leituras? ");
    if (scanf("%zu", &n) != 1 || n == 0) { // Verifica se o número de leituras é válido.
        fprintf(stderr, "Número inválido.\n");
        return 1;
    }

    float *leituras = malloc(n * sizeof *leituras); // Aloca memória para o vetor de leituras.
    if (!leituras) { // Verifica se a alocação de memória foi bem-sucedida.
        fprintf(stderr, "Erro de memória.\n");
        return 1;
    }

    for (size_t i = 0; i < n; ++i) { // Loop para ler as leituras.
        for (;;) { // Loop para verificar se a leitura é válida.
            printf("Leitura %zu: ", i + 1); // Solicita a leitura do usuário.
            if (scanf("%f", &leituras[i]) == 1) { // Verifica se a leitura é válida.
                break;
            }
            fputs("Entrada inválida. Tente novamente.\n", stderr); // Exibe uma mensagem de erro se a leitura não for válida.
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF); // Limpa o buffer de entrada.
        }
    }

    float media, min, max; // Variáveis para armazenar a média, o menor e o maior valor.
    estatisticas(leituras, n, &media, &min, &max); // Calcula as estatísticas do vetor de leituras.

    printf("\n» Resultados:\n");
    printf("- Média : %.2f\n", media);
    printf("- Mínimo : %.2f\n", min);
    printf("- Máximo : %.2f\n", max);

    free(leituras);
    return 0;
}

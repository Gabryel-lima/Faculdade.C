
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Init {
    char ru[10];
    char nomeArquivo[14];
};

struct Pessoa {
    char nome[100];
    char cpf[15];
    char telefone[15];
    char email[100];
};

void ConstroiMenu() {
    printf("\n");
    for (size_t i = 0; i < 30; i++) {
        printf("+");
    }
    printf("\n");
    printf("*");
    printf("         ");
    printf("Bem vindo!");
    printf("         ");
    printf("*");
    printf("\n");
    for (size_t j = 0; j < 30; j++) {
        printf("+");
    }
}

void Entrada(struct Init *ref) {
    wprintf(L"\n\nDigite o seu número de Registro Único (RU): ");
    scanf("%s", ref->ru);
}

void coletarInformacoes(struct Pessoa *registro) {
    printf("\nNome: ");
    scanf("%s", registro->nome);

    printf("CPF: ");
    scanf("%s", registro->cpf);

    wprintf(L"Telefone (DDD+Número): ");
    scanf("%s", registro->telefone);

    printf("E-mail: ");
    scanf("%s", registro->email);
}

void Coleta(struct Pessoa registros[], int numRepeticoes) {
    for (int i = 0; i < numRepeticoes; i++) {
        printf("\nRegistro [%d]\n", i + 1);
        coletarInformacoes(&registros[i]);
    }
}

void CriaCSV(struct Init *ref) {
    sprintf(ref->nomeArquivo, "%s.csv", ref->ru);
}

void SalvarEmCSV(struct Init *nomeArquivo, struct Pessoa registros[], int numRepeticoes) {
    FILE *arquivo = fopen(nomeArquivo->nomeArquivo, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    for (int i = 0; i < numRepeticoes; i++) {
        fprintf(arquivo, "%s;%s;%s;%s\n", registros[i].nome, registros[i].cpf, registros[i].telefone, registros[i].email);
    }

    fclose(arquivo);
    printf("\nOs dados foram salvos no arquivo %s.\n", nomeArquivo->nomeArquivo);
}

void Run() {
    setlocale(LC_ALL, "Portuguese");

    struct Init Init;
    struct Pessoa registros[10];

    ConstroiMenu();
    Entrada(&Init);

    int numDigitosRU = strlen(Init.ru);
    Coleta(registros, numDigitosRU);

    CriaCSV(&Init);
    SalvarEmCSV(&Init, registros, numDigitosRU);
}

int main() {
    Run();

    return 0;
}

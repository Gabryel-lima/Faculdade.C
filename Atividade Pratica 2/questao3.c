#include <stdio.h> // Hearder de entrada e saída.
#include <ctype.h> // Header de funções para manipulação de caracteres.
#include <string.h> // Header de funções para manipulação de strings.
#include <locale.h> // hearder que define um conjunto de convenções culturais usadas para formatação de texto, números, datas, ordenação alfabética, etc.

void encrypt(char *s) {
    /*
    Função para criptografar uma string.
    - s: string a ser criptografada.
    */
    const char vowel_to_digit[256] = { // Define as vogais maiúsculas e minúsculas e seus respectivos dígitos.
        ['A'] = '2', ['a'] = '2',
        ['E'] = '3', ['e'] = '3', 
        ['I'] = '4', ['i'] = '4',
        ['O'] = '5', ['o'] = '5',
        ['U'] = '6', ['u'] = '6' 
    };
    
    const char digit_to_vowel[10] = // Define os dígitos e as vogais maiúsculas e minúsculas.
        {'a','e','i','o','u','A','E','I','O','U'};

    for (char *p = s; *p != '\0'; ++p) { // Loop para criptografar a string.
        unsigned char c = *p; // Variável para armazenar o caractere atual.
        if (vowel_to_digit[c] != 0) { // Verifica se o caractere é uma vogal.
            *p = vowel_to_digit[c]; // Substitui o caractere por seu respectivo dígito.
        } else if (isdigit(c)) { // Verifica se o caractere é um dígito.
            *p = digit_to_vowel[c - '0']; // Substitui o caractere por sua respectiva vogal.
        }
    }
}

int main(void) {
    /*
    Função principal do programa.
    - setlocale: define o locale do programa para garantir que o programa funcione corretamente em qualquer sistema operacional.
    - printf: exibe uma mensagem de boas-vindas.
    - fgets: lê a frase do usuário.
    - encrypt: criptografa a frase.
    */

    // Salva guarda para o setlocale() para garantir que o programa funcione corretamente em qualquer sistema operacional.
    if (!setlocale(LC_ALL, "pt_BR.UTF-8")) {
        fputs("Locale pt_BR.UTF-8 indisponivel\n", stderr);
    }

    printf("\n+++ Questão 3 +++\n");

    char frase[100]; // Variável para armazenar a frase do usuário.

    printf("\nDigite uma frase {máx. 100 char}: ");
    if (fgets(frase, sizeof frase, stdin)) { // Lê a frase do usuário.
        frase[strcspn(frase, "\n")] = '\0'; // Remove o caractere de nova linha da frase.

        encrypt(frase); // Criptografa a frase.
        printf("\nFrase criptografada: %s\n\n", frase); // Exibe a frase criptografada.
    }

    return 0;
}

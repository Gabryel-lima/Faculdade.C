/* Uma empresa deseja criar um sistema para cadastrar funcionários. Cada funcionário tem um nome, um cargo e um salário. O nome pode 
ter  no  máximo  50  caracteres  e  o  cargo  pode  ter  até  30  caracteres.  Após  cadastrar  5  funcionários,  o  sistema  deve  verificar  se  há  algum 
funcionário com o mesmo cargo e, se houver, exibir os detalhes desses funcionários. */

/*
 * Sistemas simples de cadastro de funcionários
 * 
 * 
*/

#include <stdio.h> // hearder de input e output
#include <locale.h> // hearder de conjunto de convenções semânticas
#include <string.h> // funções para manipulação de strings

#include "../q1/livros"

typedef struct cadastros {
    char nome[51]; // Max de 50 char 
    char cargo[31]; // Max de 30 char
    double salario;
} Cadastros;

int main(void) {
    
}

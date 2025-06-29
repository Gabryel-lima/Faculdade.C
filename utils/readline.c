#include <stdio.h>          /* fgets  */
#include <string.h>         /* strcspn */
#include "readline.h" // my header

/*----------------------------------------------------------*/
/* Função utilitária: lê uma linha com segurança,           *
 * removendo o '\n' inserido por fgets, se existir.         */
void read_line(char *dest, size_t lenght) {
    if(fgets(dest, (int)lenght, stdin) == NULL) {
        dest[0] = '\0'; /* EOF inesperado ⟶ string vazia */
        return;
    }
    dest[strcspn(dest, "\n")] = '\0'; 
}
/*----------------------------------------------------------*/

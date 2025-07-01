#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define VALUE_LEN 20
#define TYPE_LEN 20

typedef struct Component {
    char name[NAME_LEN + 1];   /* +1 for null‑terminator */
    char value[VALUE_LEN + 1];
    char type[TYPE_LEN + 1];
    struct Component *next;
} Component;

/*----------------------------------------------------------*/
/*      Estrutura que representa um componente eletrônico   */
/*----------------------------------------------------------*/

/*----------------------------------------------------------*/
/*      Funções utilitárias                                 */
/*----------------------------------------------------------*/
// Função para limpar o buffer de entrada padrão (stdin)
static void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para ler uma linha do usuário com prompt e tamanho máximo
static void read_line(char *dest, size_t len, const char *prompt) {
    printf("%s", prompt);
    if (fgets(dest, (int)len, stdin) == NULL) {
        dest[0] = '\0';
        return;
    }
    dest[strcspn(dest, "\n")] = '\0'; /* remove '\n' */
}

/*----------------------------------------------------------*/
/*  Operações sobre a lista encadeada                       */
/*----------------------------------------------------------*/
// Cria um novo nó (componente) com os dados fornecidos
static Component *create_node(const char *name, const char *value, const char *type) {
    Component *node = (Component *)malloc(sizeof(Component));
    if (!node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strncpy(node->name,  name,  NAME_LEN);  node->name[NAME_LEN]  = '\0';
    strncpy(node->value, value, VALUE_LEN); node->value[VALUE_LEN] = '\0';
    strncpy(node->type,  type,  TYPE_LEN);  node->type[TYPE_LEN]  = '\0';
    node->next = NULL;
    return node;
}

// Insere um novo componente no início da lista
static void insert_front(Component **head, const char *name, const char *value, const char *type) {
    Component *node = create_node(name, value, type);
    node->next = *head;
    *head = node;
}

// Insere um novo componente no final da lista
static void insert_back(Component **head, const char *name, const char *value, const char *type) {
    Component *node = create_node(name, value, type);
    if (*head == NULL) {
        *head = node;
        return;
    }
    Component *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

// Lista todos os componentes presentes na lista encadeada
static void list_components(const Component *head) {
    puts("\n--- Lista de Componentes ---");
    int idx = 1;
    while (head) {
        printf("%02d. %-*s | %-*s | %-*s\n", idx, NAME_LEN, head->name,
               VALUE_LEN, head->value, TYPE_LEN, head->type);
        head = head->next;
        ++idx;
    }
    if (idx == 1) puts("(lista vazia)");
}

// Salva a lista de componentes em um arquivo CSV
static void save_csv(const Component *head, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("fopen");
        return;
    }
    fprintf(f, "Nome; Valor; Tipo\n");
    while (head) {
        fprintf(f, "%s;%s;%s\n", head->name, head->value, head->type);
        head = head->next;
    }
    fclose(f);
    printf("Arquivo '%s' salvo com sucesso.\n", filename);
}

// Libera toda a memória alocada para a lista de componentes
static void free_list(Component **head) {
    while (*head) {
        Component *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

/*----------------------------------------------------------*/
/*  Função principal                                        */
/*----------------------------------------------------------*/
// Função principal: apresenta o menu e executa as operações
int main(void) {
    Component *head = NULL;
    int opcao;

    do {
        puts("\n===== Menu =====");
        puts("1. Inserir componente (início)");
        puts("2. Inserir componente (fim)");
        puts("3. Listar componentes");
        puts("4. Gerar CSV");
        puts("5. Sair");
        printf("Escolha: ");
        if (scanf("%d", &opcao) != 1) {
            opcao = 0; /* força 'default' */
        }
        clear_stdin(); /* remove resto da linha */

        char nome[NAME_LEN + 1], valor[VALUE_LEN + 1], tipo[TYPE_LEN + 1];
        switch (opcao) {
            case 1:
            case 2:
                read_line(nome, sizeof(nome),  "Nome   : ");
                read_line(valor, sizeof(valor),"Valor  : ");
                read_line(tipo, sizeof(tipo),  "Tipo   : ");
                if (opcao == 1)
                    insert_front(&head, nome, valor, tipo);
                else
                    insert_back(&head, nome, valor, tipo);
                break;
            case 3:
                list_components(head);
                break;
            case 4:
                save_csv(head, "./componentes.csv");
                break;
            case 5:
                break;
            default:
                puts("Opção inválida.");
        }
    } while (opcao != 5);

    free_list(&head);
    return 0;
}

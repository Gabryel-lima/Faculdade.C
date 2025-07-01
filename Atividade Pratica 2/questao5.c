#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC 100
#define RU "1234567.csv"

typedef struct Tarefa {
    int id;
    char desc[MAX_DESC + 1];
    int prio;                 /* 1-alta | 2-média | 3-baixa */
    struct Tarefa *next;
} Tarefa;

/* Lê uma linha removendo '\n'; devolve 0 em EOF */
static int read_line(char *buf, size_t len) {
    if (!fgets(buf, (int)len, stdin)) return 0;
    buf[strcspn(buf, "\n")] = '\0';
    return 1;
}

/* Insere ordenado por prioridade; devolve novo head */
Tarefa *inserir(Tarefa *head, int id, const char *d, int p) {
    Tarefa *novo = malloc(sizeof *novo);
    if (!novo) { perror("malloc"); exit(EXIT_FAILURE); }
    novo->id   = id;
    strncpy(novo->desc, d, MAX_DESC); novo->desc[MAX_DESC] = '\0';
    novo->prio = p;

    /* se lista vazia ou prioridade melhor que a do head */
    if (!head || p < head->prio) {
        novo->next = head;
        return novo;
    }
    /* busca posição */
    Tarefa *cur = head;
    while (cur->next && cur->next->prio <= p)
        cur = cur->next;
    novo->next = cur->next;
    cur->next  = novo;
    return head;
}

/* Remove e devolve ponteiro para a tarefa removida (maior prioridade = primeira) */
Tarefa *remover_max(Tarefa **head) {
    if (!*head) return NULL;
    Tarefa *rem = *head;
    *head = (*head)->next;
    rem->next = NULL;
    return rem;
}

/* Procura por id e permite editar descrição e prioridade */
void editar(Tarefa *head, int id) {
    for (Tarefa *cur = head; cur; cur = cur->next) {
        if (cur->id == id) {
            printf("Descrição atual: %s\nNova descrição: ", cur->desc);
            read_line(cur->desc, sizeof cur->desc);
            printf("Prioridade atual: %d\nNova prioridade (1-3): ", cur->prio);

            if (scanf("%d%*c", &cur->prio) != 1) {
                fprintf(stderr, "Erro ao ler prioridade.\n");
                return;
            } /* consome '\n' com %*c */

            printf("Tarefa %d atualizada.\n", id);
            return;
        }
    }
    puts("ID não encontrado.");
}

/* Lista todas as tarefas */
void listar(const Tarefa *head) {
    puts("\n--- Lista de Tarefas ---");
    for (const Tarefa *cur = head; cur; cur = cur->next)
        printf("ID:%d | P:%d | %s\n", cur->id, cur->prio, cur->desc);
    puts("------------------------\n");
}

/* Formato: id;descricao;prioridade\n */
void salvar_csv(const Tarefa *head, const char *arq) {
    FILE *fp = fopen(arq, "w");
    if (!fp) { perror("fopen"); return; }
    for (const Tarefa *cur = head; cur; cur = cur->next)
        fprintf(fp, "%d;%s;%d\n", cur->id, cur->desc, cur->prio);
    fclose(fp);
}

/* Carrega arquivo; devolve head */
Tarefa *carregar_csv(const char *arq) {
    FILE *fp = fopen(arq, "r");
    if (!fp) return NULL;        /* não existe ainda */
    Tarefa *head = NULL;
    char linha[256];
    while (fgets(linha, sizeof linha, fp)) {
        int id, pr;
        char desc[MAX_DESC + 1];
        if (sscanf(linha, "%d;%100[^;];%d", &id, desc, &pr) == 3)
            head = inserir(head, id, desc, pr);
    }
    fclose(fp);
    return head;
}

int main(void) {
    Tarefa *lista = carregar_csv(RU);
    int opcao;

    do {
        puts("1) Inserir  2) Remover máx  3) Editar  4) Listar  5) Sair");
        printf("Escolha: ");
        if (scanf("%d%*c", &opcao) != 1) break;

        if (opcao == 1) {               /* Inserir */
            int id, pr;
            char desc[MAX_DESC + 1];
            printf("ID: ");   if(scanf("%d%*c", &id) != 1) break;
            printf("Descrição: "); read_line(desc, sizeof desc);
            do { printf("Prioridade (1-3): "); if(scanf("%d%*c", &pr) != 1) break; } while (pr < 1 || pr > 3);
            lista = inserir(lista, id, desc, pr);

        } else if (opcao == 2) {        /* Remover */
            Tarefa *rem = remover_max(&lista);
            if (rem) {
                printf("\nRemovida tarefa ID %d (%s)\n", rem->id, rem->desc);
                free(rem);
            } else puts("Lista vazia.");

        } else if (opcao == 3) {        /* Editar */
            int id; printf("ID a editar: "); if(scanf("%d%*c", &id) != 1) break;
            editar(lista, id);

        } else if (opcao == 4) {        /* Listar */
            listar(lista);
        }

    } while (opcao != 5);

    salvar_csv(lista, RU);
    /* libera memória */
    while (lista) { Tarefa *tmp = lista; lista = lista->next; free(tmp); }
    puts("Dados salvos. Encerrando...");
    return 0;
}

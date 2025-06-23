# ---------------------------------------
# Variáveis de configuração
# ---------------------------------------

CC      = gcc            # nome do compilador C
CFLAGS  = -std=c99 -Wall -O2   # opções passadas ao compilador
OBJ     = livros.o utils/readline.o   # object files que compõem o programa

# ---------------------------------------
# Alvo principal (target) que gera o executável
# ---------------------------------------

livros: $(OBJ)          # 'livros' depende de todos os arquivos listados em $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	#        │      │  │ │
	#        │      │  │ └─ $^ → lista de pré-requisitos (aqui, os .o)
	#        │      │  └────── $@ → nome do alvo (aqui, 'livros')
	#        │      └───────── opções de compilação (CFLAGS)
	#        └──────────────── compilador (CC)

# ---------------------------------------
# Regra-padrão (pattern rule) para transformar .c em .o
# ---------------------------------------

%.o: %.c                # para qualquer arquivo X.c gera-se X.o
	$(CC) $(CFLAGS) -c $< -o $@
	#        │      │  │    │
	#        │      │  │    └─ $@ → nome do .o a produzir
	#        │      │  └────── $< → primeiro pré-requisito, isto é, o .c
	#        │      └───────── opções de compilação (CFLAGS)
	#        └──────────────── compilador (CC)
	#
	# -c     → compila, mas NÃO liga (gera object file)
	# -o ... → define o nome do arquivo de saída

# ---------------------------------------
# Alvo auxiliar para limpeza
# ---------------------------------------

clean:                  # alvo "phony" (não gera arquivo real)
	rm -f $(OBJ) livros  # remove os .o e o executável

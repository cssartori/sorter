typedef struct Pilha_quicks{
    int ini;
    int fim;
    struct Pilha_quicks *baixo;
} pilhaq;

typedef struct Lista{
    int chave;
    struct Lista *prox;
    struct Lista *ant;
} lista;


pilhaq* desempilha(pilhaq *p, int *a, int *b);
pilhaq* insere_pilha(pilhaq *p, int a, int b);
lista *inserir_lista_ordenada(int c, lista *list);

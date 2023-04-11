

typedef struct stack {
    int valor;
    struct stack * proximo;
} stack;

stack * criar_pilha();

bool pilha_vazia(stack * pilha);

void empilhar(stack * pilha, int valor);

int desempilhar(stack * pilha);

void printar_pilha(stack * pilha);

int topo_valor(stack * pilha);

int tamanho_pilha(stack * pilha);

stack * inverte_pilha(stack * pilha);

stack * unir_pilhas(stack * pilha1, stack * pilha2);
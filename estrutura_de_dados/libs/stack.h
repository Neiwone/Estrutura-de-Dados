#define MAXN 20

typedef struct stack {
    int topo;
    int elemento[MAXN];
} stack;

// Retorna topo.
int criar_pilha(stack * pilha);

// Retorna true caso seja a pilha esteja vazia e false caso contrario.
bool pilha_vazia(stack * pilha);

// Retorna true caso a pilha esteja cheia e false caso contrario.
bool pilha_cheia(stack * pilha);

// Retorna true caso seja possivel empilhar um valor na pilha e false caso contrario.
bool empilhar(stack * pilha, int valor);

// Retorna o valor desempilhado.
int desempilhar(stack * pilha);

// Printar todos os valores de uma pilha.
int printar_pilha(stack * pilha, int i);

// Retorna o valor do topo da pilha.
int topo_valor(stack * pilha);

// Retorna o tamanho da pilha.
int tamanho_pilha(stack * pilha);

// Retorna a pilha invertida.
stack * inverte_pilha(stack * pilha);

// Retorna a pilha1 que foi unida com a pilha2.
stack * unir_pilhas(stack * pilha1, stack * pilha2);

// Retorna pilha ordenada via bubble sort.
stack * ordenar_pilha(stack * pilha);
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    int ehoprimeiro;
    struct elemento *proximo;
    
};

//função para inserir novos elementos 
void inserir_elemento(struct elemento *fila, int num)
{
    struct elemento *temporario = fila;

    while(temporario->proximo != NULL) temporario = temporario->proximo;

    struct elemento *novoelemento = malloc(sizeof(struct elemento));

    novoelemento->valor = num;
    novoelemento->proximo = NULL;
    temporario->proximo = novoelemento;
    
}

void printar(struct elemento *fila)
{
    struct elemento *temporario = fila->proximo;

    while(temporario != NULL)
    {
        printf("%d", temporario->valor);
        temporario = temporario->proximo;
        if(temporario != NULL) printf(", ");
    }
    printf("\n");
}

void tamanho(struct elemento *fila)
{
    struct elemento * temporario = fila;
    int i = 0;
    while(temporario->proximo != NULL)
    {
        temporario = temporario->proximo;
        i++;
    }

    printf("o tamanho da fila eh de %d elementos\n", i);
}

void ultimo(struct elemento *fila)
{
    struct elemento *temporario = fila;

    while(temporario->proximo != NULL) temporario = temporario->proximo;

    printf("ultimo da fila: %d\n", temporario->valor);
}

void primeiro(struct elemento *fila)
{
    struct elemento *temporario = fila->proximo;

    while(temporario->anterior != NULL) temporario = temporario->anterior;

    printf("primeiro da fila: %d\n", temporario->valor);
}

int main()
{
    int num;
    struct elemento *fila = malloc(sizeof(struct elemento));
    fila->proximo = NULL;
    fila->anterior = NULL;

    printf("Digite os elementos que pertencerao a fila (digite qualquer letra para sair): \n");
    while(scanf("%d", &num) == 1) inserir_elemento(fila, num);

    printar(fila);
    tamanho(fila);
    primeiro(fila);
    ultimo(fila);

    return 0;
}
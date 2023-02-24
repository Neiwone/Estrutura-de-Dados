#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    //valor do elemento
    int valor;
    //ponteiro para o proximo elemento
    struct elemento *proximo;
    };

struct elemento * definir_lista()
{
    struct elemento *primeiro = malloc(sizeof(struct elemento));
    primeiro -> proximo = NULL;
    return primeiro;
}

void inserir_elemento(struct elemento *lista, int num)
{
    struct elemento *temporario = lista;

    while(temporario->proximo != NULL) temporario = temporario->proximo;

    struct elemento * novoelemento = malloc(sizeof(struct elemento));
    novoelemento->valor = num;
    novoelemento->proximo = NULL;
    temporario->proximo = novoelemento;
    
}

void printar(struct elemento *lista)
{
    struct elemento * temporario = lista->proximo;

    while(temporario != NULL)
    {
        printf("%d", temporario->valor);
        temporario = temporario->proximo;
        if(temporario != NULL) printf(", ");
    }
}



int main()
{
    int num;
    struct elemento *lista = definir_lista();    


    while(scanf("%d", &num) == 1) inserir_elemento(lista, num);
    
    printar(lista);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    int primeiro;
    int ultimo;
    struct elemento *proximo;
    
}fila;

void criar_fila(fila *filaprincipal)
{
    filaprincipal->primeiro = -1;
    filaprincipal->ultimo = -1;
    filaprincipal->proximo = NULL;
}

void inserir_elemento(fila *fila, int num)
{
    struct elemento *temporario = fila;
    int i = 0;

    while(temporario->proximo != NULL)
    {
        temporario = temporario->proximo;
        i++;
    }

    if (temporario->primeiro == -1 && i > 0)
    {
        temporario->ultimo = 0;

        struct elemento *novoelemento = malloc(sizeof(struct elemento));
    
        novoelemento->valor = num;
        novoelemento->primeiro = 0;
        novoelemento->ultimo = -1;
        novoelemento->proximo = NULL;
        temporario->proximo = novoelemento;
        return;
    }

    if (temporario->primeiro == -1 && i == 0)
    {
        temporario->primeiro == 0;
        temporario->ultimo == 0;

        struct elemento *novoelemento = malloc(sizeof(struct elemento));
    
        novoelemento->valor = num;
        novoelemento->primeiro = -1;
        novoelemento->ultimo = -1;
        novoelemento->proximo = NULL;
        temporario->proximo = novoelemento;
        return;
    }
    
    
    temporario->ultimo = 0;

    struct elemento *novoelemento = malloc(sizeof(struct elemento));

    novoelemento->valor = num;
    novoelemento->primeiro = 0;
    novoelemento->ultimo = -1;
    novoelemento->proximo = NULL;
    temporario->proximo = novoelemento;
    
}

void printar(fila *fila)
{
    struct elemento *temporario = fila->proximo;

    while(temporario != NULL)
    {
        //printf("%d %d %d", temporario->valor, temporario->primeiro, temporario->ultimo);
        printf("%d", temporario->valor);
        temporario = temporario->proximo;
        if(temporario != NULL) printf(", ");
    }
    printf("\n");
}

void tamanho(fila *fila)
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

void primeiro_ultimo(fila *fila)
{
    struct elemento * temporario = fila->proximo;

    while (temporario->primeiro != -1)temporario = temporario->proximo;
    printf("o valor do primeiro da fila eh: %d \n", temporario->valor);
    
    temporario = fila->proximo;
    while (temporario->ultimo != -1)temporario = temporario->proximo;
    printf("o valor do ultimo da fila eh: %d \n", temporario->valor);    
}

void remover_elemento(fila *fila)
{
    struct elemento *temporario = fila->proximo;

    temporario->proximo->primeiro = -1;
    fila->proximo = temporario->proximo;
    free(temporario);

}

void concatenacao(struct elemento * fila, struct elemento * fila2)
{
    struct elemento * temporario = fila;
    while(temporario->proximo != NULL) temporario = temporario->proximo;

    temporario->ultimo = 0;
    fila2->proximo->primeiro = 0;
    temporario->proximo = fila2->proximo;
}

int main()
{
    int num, num2;
    fila *filaprincipal = malloc(sizeof(fila));
    criar_fila(filaprincipal);
    fila *filaprincipal2 = malloc(sizeof(fila));

    printf("Digite os elementos que pertencerao a fila (digite qualquer letra para sair): ");
    while(scanf("%d", &num) == 1) inserir_elemento(filaprincipal, num);

    char c;
    scanf(" %c", &c);

    printf("\n");
    printf("Fila: ");
    printar(filaprincipal);
    printf("\n");

    int escolha;
    printf("1.Tamanho da fila\n");
    printf("2.Retornar o valor do primeiro e do ultimo da fila \n");
    printf("3.Remover um elemento da fila\n");
    printf("4.Realizar uma concatenacao entre duas filas\n");
    printf("5.Inserir um elemento na fila\n");
    printf("6.Cancelar\n");
    printf("\nInforme a opcao: ");
    scanf("%d", &escolha);
    printf("\n");
    switch (escolha)
    {
        case 1:
        tamanho(filaprincipal);
        break;
        case 2:
        primeiro_ultimo(filaprincipal);
        break;
        case 3:
        printf("removendo um elemento da fila...\n");
        remover_elemento(filaprincipal);
        printf("fila atual: \n");
        printar(filaprincipal);
        break;
        case 4:
        printf("Digite os elementos que pertencerao a sua segunda fila (digite qualquer letra para sair): ");
        criar_fila(filaprincipal2);
        while(scanf("%d", &num2) == 1) inserir_elemento(filaprincipal2, num2);
        concatenacao(filaprincipal, filaprincipal2);
        printar(filaprincipal);
        break;
        case 5:
        printf("Digite o numero que deseja inserir na fila: ");
        printf("\n");
        scanf("%d", &num);
        inserir_elemento(filaprincipal, num);
        printf("fila atual: ");
        printar(filaprincipal);
        break;
        case 6:
        exit(0);
        default:
        printf("opcao invalida!\n");
    }
    return 0;
}
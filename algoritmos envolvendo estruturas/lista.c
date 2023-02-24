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
    primeiro->proximo = NULL;
    return primeiro;
}

//função para inserir novos elementos 
void inserir_elemento(struct elemento *lista, int num)
{
    //duplicação da lista para percorrê-la sem perder o endereço da propria lista
    struct elemento *temporario = lista;

    //while para percorrer até o elemento que o próximo é o NULL
    while(temporario->proximo != NULL) temporario = temporario->proximo;

    //alocação do novo elemento na memoriam, atribuição do valor do novo elemento
    struct elemento * novoelemento = malloc(sizeof(struct elemento));
    novoelemento->valor = num;
    //atribuição do endereço do próximo como NULL
    novoelemento->proximo = NULL;
    temporario->proximo = novoelemento;
    
}

//funcão para printar todos elementos da lista até chegar no NULL
void printar(struct elemento *lista)
{
    struct elemento * temporario = lista->proximo;

    while(temporario != NULL)
    {
        printf("%d", temporario->valor);
        temporario = temporario->proximo;
        if(temporario != NULL) printf(", ");
    }
    printf("\n");
}

//funcão para remover um elemento da lista
/*void remover_elemento(struct elemento *lista, int numero_desejado)
{

    struct elemento *temporario = lista;
    while (temporario != NULL && temporario->valor != numero_desejado) temporario = temporario->proximo;
    
    if (temporario != NULL)
    {
        free(temporario);
        remover_elemento(lista, numero_desejado);
        return;
        
    }
    printf("Numero %d nao encontrado :(\n", numero_desejado);
    return;
    
}
*/

//funcão para calcular o tamanho da lista
int tamanho(struct elemento *lista)
{
    struct elemento * temporario = lista;
    int i = 0;
    while(temporario->proximo != NULL)
    {
        temporario = temporario->proximo;
        i++;
    }

    return i;
}

//funcão para achar o elemento cabeça da lista
void elemento_cabeca(struct elemento *lista)
{
    struct elemento * temporario = lista->proximo;
    if (temporario != NULL)
    {
        printf("Cabeca da lista: %d\n", temporario->valor);
        return;
    }
    else
    {
        printf("A lista não tem cabeca\n");
        return;
    }
    
}

//funcão para printar a cauda da lista
void calda_lista(struct elemento *lista)
{
    struct elemento * temporario = lista->proximo;

    temporario = temporario->proximo;
    printf("Calda da lista: ");
    while(temporario != NULL)
    {
        printf("%d", temporario->valor);
        temporario = temporario->proximo;
        if(temporario != NULL) printf(", ");
    }
    printf("\n");

}

//funcão para procurar se certo elemento é membro da lista
void procurar_elemento(struct elemento * lista, int numero_desejado)
{
    struct elemento * temporario = lista;
    while (temporario != NULL && temporario->valor != numero_desejado) temporario = temporario->proximo;
    
    if (temporario != NULL) printf("Numero %d encontrado!\n", numero_desejado);
    else printf("Numero %d nao encontrado :(\n", numero_desejado);

}

//funcão para concatenar duas listas
void concatenacao(struct elemento * lista, struct elemento * lista2)
{
    struct elemento * temporario = lista;
    while(temporario->proximo != NULL) temporario = temporario->proximo;

    temporario->proximo = lista2->proximo;
}

//funcão para inverter uma lista
void inverter_lista(struct elemento ** lista)
{
    struct elemento * anterior = NULL;
    struct elemento * atual = *lista;
    struct elemento * proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    *lista = anterior;
}

int main()
{
    struct elemento *lista = definir_lista();
    int num, num2, membro;
    struct elemento *lista2 = definir_lista();

    printf("Digite os elementos que pertencerao a lista (digite qualquer letra para sair): ");
    //while para ler os numeros até a leitura falhar e inserir na lista todos numeros lidos
    while(scanf("%d", &num) == 1) inserir_elemento(lista, num);
    char c;
    scanf(" %c", &c);

    printf("\n");
    printf("Lista: ");
    printar(lista);
    printf("\n");

    int escolha;
    printf("1.Tamanho da lista\n");
    printf("2.Conferir se certo numero eh um membro da lista\n");
    printf("3.Mostar qual elemento da lista eh a cabeca\n");
    printf("4.Remover determinado elemetno da lista\n");
    printf("5.Retornar a cauda da lista\n");
    printf("6.Realizar uma concatenacao entre duas listas\n");
    printf("7.Inverter a lista\n");
    printf("8.Cancelar\n");
    printf("\nInforme a opcao: ");
    scanf("%d", &escolha);
    switch (escolha)
    {
        case 1:
        printf("Quantidade de elementos na lista: %d\n", tamanho(lista));
        break;
        case 2:
        printf("Digite o numero que deseja checar: \n");
        scanf("%d", &membro);
        procurar_elemento(lista, membro);
        break;
        case 3:
        elemento_cabeca(lista);
        break;
        case 4:
        printf("(!) INDISPONIVEL (!)");
        //printf("removendo elemento %d da lista: ", 2);
        //remover_elemento(lista, 2);
        //printar(lista);
        break;
        case 5:
        calda_lista(lista);
        break;
        case 6:
        printf("Digite os elementos que pertencerao a sua segunda lista (digite qualquer letra para sair): ");
        while(scanf("%d", &num2) == 1) inserir_elemento(lista2, num2);
        concatenacao(lista, lista2);
        printar(lista);
        break;
        case 7:
        printf("(!) INDISPONIVEL (!)");
        //inverter_lista(&lista);
        //printf("Lista invertida: ");
        //printar(lista);
        break;
        case 8:
        exit(0);
        default:
        printf("opcao invalida!\n");
    } 
    

    return 0;
}
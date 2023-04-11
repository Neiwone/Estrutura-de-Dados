#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stackdinamica.h"

stack * criar_pilha() {

    stack * pilha = malloc(sizeof(stack));
    pilha->proximo = NULL;
    return pilha;
}

bool pilha_vazia(stack * pilha) {
    return (pilha->proximo == NULL) ? true : false;
}

void empilhar(stack * pilha, int valor) {
    
    stack * temporario = malloc(sizeof(stack));
    temporario->valor = valor;
    temporario->proximo = pilha->proximo;
    pilha->proximo = temporario;
    return;
}

int desempilhar(stack * pilha) {

    stack * temporario = pilha->proximo;
    int aux = temporario->valor;
    pilha->proximo = temporario->proximo;
    free(temporario);
    return aux;
}

void printar_pilha(stack * pilha) {
    
    if(pilha_vazia(pilha) == true) return (void) printf("a pilha esta vazia!\n");

    stack * temporario = pilha->proximo;
    while(temporario != NULL)
    {
        printf("%d", temporario->valor);
        temporario = temporario->proximo;
        if(temporario != NULL) printf(", ");
    }
    return (void) printf(". \n");
}

int topo_valor(stack * pilha) {

    if(pilha_vazia(pilha) == true) return printf("pilha vazia.\n");

    return pilha->proximo->valor;
}

int tamanho_pilha(stack * pilha) {

    int i;
    stack * temporario = pilha;
    while(temporario->proximo != NULL) {
        temporario = temporario->proximo;
        i++;
    }
    return i;
}

stack * inverte_pilha(stack * pilha) {

    stack * pilhainvertida = criar_pilha(pilhainvertida);
    stack * temporario = pilha->proximo;
    while(temporario != NULL)
    {
        empilhar(pilhainvertida, temporario->valor);
        temporario = temporario->proximo;
    }
    return pilhainvertida;
}

stack * unir_pilhas(stack * pilha1, stack * pilha2) {

    pilha2 = inverte_pilha(pilha2);

    while(pilha2 != NULL)
    {
        empilhar(pilha1, pilha2->valor);
        pilha2 = pilha2->proximo;
    }

    return pilha1;

}

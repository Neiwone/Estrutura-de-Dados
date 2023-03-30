#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int criar_pilha(stack * pilha) {

    pilha->topo = -1;
    return pilha->topo;
}

bool pilha_vazia(stack * pilha) {
    return (pilha->topo == -1) ? true : false;
}

bool pilha_cheia(stack * pilha) {
    return (pilha->topo + 1 < MAXN) ? false : true;
}

bool empilhar(stack * pilha, int valor) {
    
    if (pilha_cheia(pilha) == true) {
        printf("pilha cheia. :(\n");
        return false;
    }

    pilha->topo+=1;
    pilha->elemento[pilha->topo] = valor;
    return true;
}

int desempilhar(stack * pilha) {

    int aux = pilha->elemento[pilha->topo];
    pilha->topo--;
    return aux;
}

int printar_pilha(stack * pilha, int i) {
    
    if(pilha_vazia(pilha) == true) return printf("a pilha esta vazia!\n");
    if(i == 0) printf("elementos da pilha: ");
    printf("%d", pilha->elemento[i]);
    if(i == pilha->topo) return printf(".\n");
    printf(", "); 
    printar_pilha(pilha, i+1);
}

int topo_valor(stack * pilha) {

    if (pilha_vazia(pilha) == false) return pilha->elemento[pilha->topo];
    return printf("pilha vazia.\n");
}

int tamanho_pilha(stack * pilha) {

    if (pilha_vazia(pilha) == false) return pilha->topo + 1;
    return printf("pilha vazia.\n");
}

stack * inverte_pilha(stack * pilha) {
    stack * pilhainvertida;
    criar_pilha(pilhainvertida);
    int tamanho = pilha->topo + 1;
    for (int i = 0; i < tamanho; i++) empilhar(pilhainvertida,desempilhar(pilha));
    return pilhainvertida;
}

stack * unir_pilhas(stack * pilha1, stack * pilha2) {
    int tamanho = pilha2->topo + 1;
    for (int i = 0; i < tamanho; i++) empilhar(pilha1,pilha2->elemento[i]);
    return pilha1;
}

stack * ordenar_pilha(stack * pilha) {
    int aux;
    int tamanho = tamanho_pilha(pilha);
    for (int j = 1; j < tamanho; j++) {
        for (int i = 0; i < tamanho - 1; i++) {
            if (pilha->elemento[i] < pilha->elemento[i + 1]) {
                aux = pilha->elemento[i];
                pilha->elemento[i] = pilha->elemento[i + 1];
                pilha->elemento[i + 1] = aux;
            }
        }
    }
    return pilha;   
}
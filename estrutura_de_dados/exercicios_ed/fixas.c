#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 10

typedef struct {
    char elementos[MAXN];
    int topo; 
} Stack;


bool isEmpty(Stack * pilha) {
    return (pilha->topo == -1) ? true : false;
}

bool isFull(Stack * pilha) {
    return (pilha->topo == MAXN) ? true : false;
}

void push(Stack * pilha, char valor) {
    pilha->elementos[++pilha->topo] = valor;
}

char pop(Stack * pilha) {
    char aux = pilha->elementos[pilha->topo--];
    return aux;
}

char top(Stack * pilha) {
    return pilha->elementos[pilha->topo];
}

bool isOperator(char valor) {
    char ops[] = "+-*/";
    for(int i = 0; i < strlen(ops); i++) if(valor == ops[i]) return true;
    return false;
}

void printStack(Stack * pilha) {
    if(isEmpty(pilha)) return (void) printf("The stack is empty!\n");

    printf("(");
    for(int i = pilha->topo; i > -1; i--)
        printf("%d%s", pilha->elementos[i], (i > 0) ? " " : "");
    printf(")\n");
}

char * infixa2posfixa(char * expressao) {
    Stack * opstack;
    
    
    for (int i = 0; i < strlen(expressao); i++)
    {
        
        
        
        
    }
    
}


int main () {
    char string[MAXN * 2];
    printf("Digite a expressao: ");
    scanf(" %[^\n]", string);

    infixa2posfixa(string);

    
}



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../libs/stack.h"


int main() {

    int opcao, valor;
    stack * pilha;
    stack * pilha1;


    // Definindo pilha para possivel união.
    pilha1->topo = criar_pilha(pilha1);

    if(criar_pilha(pilha) != -1) {
        printf("nao foi possivel criar a pilha. \n");
        return 0;
    }

    while(1)
    {
    
        printf("\n1 - Empilhar\n");
        printf("2 - Desimpilhar\n");
        printf("3 - Tamanho da pilha\n");
        printf("4 - Imprimir pilha\n");
        printf("5 - Valor do topo\n");
        printf("6 - Inverter pilha\n");
        printf("7 - Unir duas pilhas\n");
        printf("8 - Ordenar pilha\n");
        printf("0 - Sair\n\n");
        printf("opcao: ");

        scanf("%d", &opcao); 
        fflush(stdin);
        printf("\n");
               
        switch(opcao)
        {
            case 1:
                printf("Digite o valor que deseja empilhar: ");
                scanf("%d", &valor);
                fflush(stdin);

                empilhar(pilha, valor);
                printar_pilha(pilha, 0);
                break;
            case 2:
                if (pilha_vazia(pilha) == true) {
                    printf("pilha vazia. :( \n");
                    break;
                }

                printf("o elemento %d foi desempilhado. \n", desempilhar(pilha));
                printar_pilha(pilha, 0);
                break;      

            case 3:
                printf("A pilha possui %d elementos.\n", pilha->topo + 1);
                break; 
            
            case 4:
                printar_pilha(pilha, 0);
                break; 

            case 5:
                if(pilha_vazia(pilha) == false) printf("O elemento do topo e: %d.\n", topo_valor(pilha));
                else printf("pilha vazia.\n");
                break; 
            case 6:
                pilha = inverte_pilha(pilha);
                printar_pilha(pilha, 0);
                break;
            case 7:
                printf("digite os valores para a segunda pilha(Max: 10): ");
                while (scanf("%d", &valor) == 1) {
                    empilhar(pilha1, valor);
                }
                fflush(stdin);
                printar_pilha(unir_pilhas(pilha,pilha1), 0);
                break; 
            case 8:
                printar_pilha(ordenar_pilha(pilha), 0);
                break; 
            case 0:
                exit(0);
                break; 

            default:
                printf("insira um valor valido\n");
                break;    
        }
    }    
}   
    
#include <stdio.h>

typedef struct arvore{
    char valor;
    int pai;
    int filho;
    int irmaodireita;
} arvore;

void inserir(arvore A[], char elemento, char pai);
int procurar_pai(arvore A[], char valor);
int printar(arvore A[], int i);
void arvore_tabela(arvore tree[]);

int main()
{
    arvore A[100];

    A[0].valor = ' ';
    A[0].pai = -1;
    A[0].filho = -1;
    A[0].irmaodireita = -1;

    inserir(A, 'A', -1);
    inserir(A, 'B', 'A');
    inserir(A, 'C', 'A');
    inserir(A, 'D', 'B');
    inserir(A, 'E', 'B');
    inserir(A, 'F', 'C');
    inserir(A, 'G', 'C');
    inserir(A, 'H', 'F');
    inserir(A, 'I', 'F');

    //print_tree(A);
    printar(A, 0);

    0;
}

void inserir(arvore A[], char elemento, char pai)
{
    if(A[0].valor != ' ')
    {
        int i = procurar_pai(A, pai);
        if (i != -1)
        {
            int j;
            for(j = 0; A[j].valor != ' '; j++);
            A[j].valor = elemento;
            A[j].pai = i;
            A[j].filho = -1;
            A[j].irmaodireita = -1;

            if (j < 99)
            {
                A[j+1].valor = ' ';
                A[j+1].pai = -1;
                A[j+1].filho = -1;
                A[j+1].irmaodireita = -1;
            }
            
            int z = A[i].filho;
            if (z != -1)
            {
                while (A[z].irmaodireita != -1) z = A[z].irmaodireita;
                
                A[z].irmaodireita = j;
            }
            else A[i].filho = j;
        }
        else printf("o pai nao foi encontrado na arvore.\n");   
    }
    else
    {
        A[0].valor = elemento;
        A[0].pai = -1;
        A[0].filho = -1;
        A[0].irmaodireita = -1;
        A[1].valor = ' ';
        A[1].pai = -1;
        A[1].filho = -1;
        A[1].irmaodireita = -1;
    }

    return;
}

int procurar_pai(arvore A[], char valor)
{
    int i = 0;
    for (i = 0; A[i].valor != ' '; i++) if (A[i].valor == valor) break;

    if (A[i].valor == ' ') return -1;
    
    return i;
}

int printar(arvore A[], int i)
{
    if(A[i].valor == ' ') return printf("a arvore esta vazia!\n");
    printf("%c", A[i].valor);
    if(A[i].filho != -1) {printf("("); printar(A, A[i].filho);}
    else printf("()");
    if(i == 0) return 0;
    if(A[i].irmaodireita != -1) {printf(", "); printar(A, A[i].irmaodireita);}
    else printf(")");
}

void arvore_tabela(arvore tree[])
{
    printf("ID | VALUE | PARENT | LEFT | RIGHT\n");
    for(int i = 0; tree[i].valor != ' '; i++)
    {
        printf("%d | %c | %d | %d | %d\n", i, tree[i].valor, tree[i].pai, tree[i].filho, tree[i].irmaodireita);
    }
}


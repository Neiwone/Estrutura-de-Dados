// ORDER CHANGE
// INORDER -> PREORDER
// INORDER -> POSTORDER 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXS 20
// LEMBRAR DE COLOCAR AS VIRGULAS ENTRE OS OPERANDOS

// --- STACK implementation ---
typedef struct stack
{
    int elements[MAXS];
    char * el[MAXS];
    int top; 
} Stack;

void create_stack(Stack *stack)
{
    stack->top = -1;
    for(int i = 0; i < MAXS; i++)
    {
        stack->el[i] = malloc(sizeof(char *));
    }
}

void sfree(Stack * stack)
{
    for(int i = 0; i < MAXS; i++)
    {
        free(stack->el[i]);
    }
}

// push
void push(Stack *stack, int value)
{
    stack->elements[stack->top + 1] = value;
    stack->top++;
}

void pushs(Stack * stack, char * value)
{
    strcpy(stack->el[stack->top + 1], value);
    stack->top++;
}

// pop int
int pop(Stack *stack)
{
    int value = stack->elements[stack->top--];

    //printf("The element %d has pop\n", value);
    return value;
}

// pop char 
int popc(Stack *stack)
{
    int value = stack->elements[stack->top--];
    //printf("The element %c has pop\n", value);
    return value;
}

char * pops(Stack * stack)
{
    char value[100];
    strcpy(value, stack->el[stack->top--]);
    //printf("The element %s has pop\n", value);
    return stack->el[stack->top + 1];
}

// top
int top(Stack *stack)
{
    return stack->elements[stack->top];
}

char * tops(Stack * stack)
{
    return stack->el[stack->top];
}

// empty
int empty(Stack *stack)
{
    if(stack->top == -1) return 1;
    return 0;
}

// sprint
void sprint(Stack *stack)
{
    if(empty(stack))
    {
        printf("The stack is empty!\n");
        return;
    }
    printf("(");
    for(int i = stack->top; i > -1; i--)
        printf("%d%s", stack->elements[i], (i > 0) ? " " : "");
    printf(")\n");
}

// --- end STACK implementation ---

// check priority
int check_priority(char old, char new)
{
    if((old == '+' || old == '-') && (new == '*' || new == '/')) return 0;
    return 1;
}

int check_priority2(char old, char new)
{
    if((old == '*' || old == '/') && (new == '+' || new == '-')) return 1;
    return 0;
}

// get num in a expression
char * get_nums(char * exp, int * i)
{
    char * aux = malloc(sizeof(char)*10);
    int k = 0;
    while(isdigit(exp[*i]) || exp[*i] == '!')
    {
        aux[k] = exp[*i];
        k++;
        (*i)++;
    }
    aux[k] = '\0';
    return aux;
}

char * get_num_inv(char * exp, int * i)
{
    char * aux = malloc(sizeof(char)*10);
    int k = 0;
    while(isdigit(exp[*i]) || exp[*i] == '!')
    {
        aux[0] = exp[*i];
        k++;
        (*i)--;
    }
    aux[k] = '\0';

    return aux;
}

// concatenate char in the begining of a string
void strcatc(char * string1, char string2, int fb)
{
    char buffer[100];
    if(fb) sprintf(buffer, "%c %s\0", string2,  string1);
    else
    {
        sprintf(buffer, " %c\0", string2);
        strcat(string1, buffer);
        return;
    }
    strcpy(string1, buffer);
}

// concatenate string in the begining of a string
void strcats(char * string1, char * string2, int fb)
{
    char buffer[100];
    if(fb)
    {
        if(!strlen(string1)) sprintf(buffer, "%s%s\0", string2, string1);
        else sprintf(buffer, "%s %s\0", string2, string1);
    }else
    {
        if(!strlen(string1)) sprintf(buffer, "%s%s\0", string1, string2);
        else sprintf(buffer, "%s %s\0", string1, string2);
    }
    strcpy(string1, buffer);
}

int isoperator(char value)
{
    char ops[] = "+-*/^";
    for(int i = 0; i < strlen(ops);i++) if(value == ops[i]) return 1;
    return 0;
}

void inorder_to_postorder(char * exp, char * changed)
{
    int i = 0, num;
    char pre[100] = "\0", temp[20] = "\0";
    Stack *num_stack = malloc(sizeof(Stack));
    Stack *op_stack = malloc(sizeof(Stack));
    create_stack(num_stack);
    create_stack(op_stack);
    while(i < strlen(exp))
    {
        if(isdigit(exp[i]) || exp[i] == '!')
        {
            pushs(num_stack, get_nums(exp, &i));
            //printf("num_stack add %s\n", tops(num_stack));
        }
        else if(isoperator(exp[i]))
        {
            strcpy(temp, "\0");
            while(!empty(op_stack) && check_priority(top(op_stack), exp[i]))
            {
                strcpy(temp, "\0");
                //printf("Find a priority!\n");
                int count = 0;
                while(!empty(num_stack))
                {
                    if(count == 2) break;
                    // add 2 first nums
                    strcats(temp, pops(num_stack), 1);
                    count++;
                }
                strcatc(temp, popc(op_stack), 0);
                pushs(num_stack, temp);
            }
            //printf("temmp: %s\n", temp);
            push(op_stack, exp[i]);
            //printf("op_stack add %c\n", top(op_stack));
            i++;
        }
        i++;
    }

    // add other elements in stacks
    while(!empty(num_stack)) strcats(pre, pops(num_stack), 1);

    while(!empty(op_stack)) strcatc(pre, popc(op_stack), 0);
    
    printf("%s\n", pre);
    strcpy(changed, pre);
}

void postorder_to_inorder(char * exp, char * changed)
{
    int i = 0, num;
    char temp[100] = "\0";
    Stack *num_stack = malloc(sizeof(Stack));
    Stack *op_stack = malloc(sizeof(Stack));
    create_stack(num_stack);
    create_stack(op_stack);
    while(i < strlen(exp))
    {
        if(isdigit(exp[i]))
        {
            pushs(num_stack, get_nums(exp, &i));
            //printf("num_stack add %s\n", tops(num_stack));
        }
        else if(isoperator(exp[i]))
        {
            push(op_stack, exp[i]);
            //printf("op_stack add %c\n", top(op_stack));
            i++;
            strcpy(temp, "\0");
            while(!empty(op_stack))
            {
                strcpy(temp, "\0");
                //printf("Find a priority!\n");
                strcats(temp, pops(num_stack), 1); // add first num
                strcatc(temp, popc(op_stack), 1); // operator
                strcats(temp, pops(num_stack), 1); // add second num
                pushs(num_stack, temp);
            }

        }
        i++;
    }
    printf("%s\n", temp);
    strcpy(changed, temp);
}

void inorder_to_preorder(char * exp, char * changed)
{
    int i = strlen(exp) - 1, num;
    char pre[100] = "\0", temp[20] = "\0";
    Stack *num_stack = malloc(sizeof(Stack));
    Stack *op_stack = malloc(sizeof(Stack));
    create_stack(num_stack);
    create_stack(op_stack);
    while(i >= 0)
    {
        if(isdigit(exp[i]))
        {
            pushs(num_stack, get_num_inv(exp, &i));
            //printf("num_stack add %s\n", tops(num_stack));
        }
        else if(isoperator(exp[i]))
        {
            strcpy(temp, "\0");
            while(!empty(op_stack) && check_priority2(top(op_stack), exp[i]))
            {
                strcpy(temp, "\0");
                //printf("Find a priority!\n");
                int count = 0;
                while(!empty(num_stack))
                {
                    if(count == 2) break;
                    // add 2 first nums
                    strcats(temp, pops(num_stack), 0);
                    count++;
                }
                strcatc(temp, popc(op_stack), 1);
                pushs(num_stack, temp);
            }
            //printf("temmp: %s\n", temp);
            push(op_stack, exp[i]);
            //printf("op_stack add %c\n", top(op_stack));
            i--;
        }
        i--;
    }

    // add other elements in stacks
    while(!empty(num_stack)) strcats(pre, pops(num_stack), 0);

    while(!empty(op_stack)) strcatc(pre, popc(op_stack), 1);
    
    printf("%s\n", pre);
    strcpy(changed, pre);
}

void preorder_to_inorder(char * exp, char * changed)
{
    int i = strlen(exp) - 1, num;
    char temp[100] = "\0";
    Stack *num_stack = malloc(sizeof(Stack));
    Stack *op_stack = malloc(sizeof(Stack));
    create_stack(num_stack);
    create_stack(op_stack);
    while(i >= 0)
    {
        if(isdigit(exp[i]))
        {
            pushs(num_stack, get_num_inv(exp, &i));
            //printf("num_stack add %s\n", tops(num_stack));
        }
        else if(isoperator(exp[i]))
        {
            push(op_stack, exp[i]);
            //printf("op_stack add %c\n", top(op_stack));
            i--;
            strcpy(temp, "\0");
            while(!empty(op_stack))
            {
                strcpy(temp, "\0");
                //printf("Find a priority!\n");
                strcats(temp, pops(num_stack), 0); // add first num
                strcatc(temp, popc(op_stack), 0); // operator
                strcats(temp, pops(num_stack), 0); // add second num
                pushs(num_stack, temp);
            }
            //printf("temmp: %s\n", temp);

        }
        i--;
    }
    printf("%s\n", temp);
    strcpy(changed, temp);
}

void postorder_to_preorder(char * exp, char * changed)
{
    char pre[100] = "\0";
    postorder_to_inorder(exp, pre);
    inorder_to_preorder(pre, changed);
}

void preorder_to_postorder(char * exp, char * changed)
{
    char pre[100] = "\0";
    preorder_to_inorder(exp, pre);
    inorder_to_postorder(pre, changed);
}

int main()
{
    int op;
    char string[100], changed[100];

    // 2*3-4+5/3
    while(1)
    {
        printf("ESCOLHA UMA CONVERSAO:\n");
        printf("1. infixa -> prefixa 2. infixa -> posfixa\n");
        printf("3. prefixa -> infixa 4. posfixa -> infixa\n");
        printf("5. posfixa -> prefixa 6. prefixa -> posfixa\n");
        scanf("%d", &op);
        printf("Digite a expressao: ");
        scanf(" %[^\n]", string);
        switch (op)
        {
            case 1:
                inorder_to_preorder(string, changed);
                break;
            case 2:
                inorder_to_postorder(string, changed);
                break;
            case 3:
                preorder_to_inorder(string, changed);
                break;
            case 4:
                postorder_to_inorder(string, changed);
                break;
            case 5:
                postorder_to_preorder(string, changed);
                break;
            case 6:
                preorder_to_postorder(string, changed);
                break;
            default:
                printf("opção fora da lista!\n");
                break;
        }
        
    }
    return 0;
}
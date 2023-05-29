#include "binarytree.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node{
    char value;
    struct Node * left;
    struct Node * right;
} Node;

// criar árvore binária
Node * createTree(char value) {
    Node * newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// acha um nó numa árvore binária
Node * find(Node * tree, char value) {
    if(tree == NULL) return NULL;
    if (tree->value == value) return tree;

    return find(tree->left, value);
    return find(tree->right, value);
    
    return NULL;
}

// insere nó dado informação do pai 
void insert(Node * tree, char value, char parent) {
    Node * parentpointer = find(tree, parent);
    if (parentpointer == NULL) return (void) printf("pai nao encontrado.\n");
    else if(parentpointer->left == NULL) {
        Node * new = createTree(value);
        parentpointer->left = new;
    }
    else if(parentpointer->right == NULL) {
        Node * new = createTree(value);
        parentpointer->right = new;
    }
}

// printa árvore binária
void print_tree(Node * root) {
    if(root == NULL) return;
    printf("%c(", root->value);
    print_tree(root->left);
    print_tree(root->right);
    printf(")");
}

// remove no (not done)
void remove_node(Node * tree, char value) {
    Node * pointerforroot = find(tree, value);

    
}

// verifica se duas árvores binárias são iguais
bool isEqual(Node * tree1, Node * tree2) {
    if (tree1 == NULL && tree2 == NULL) return true;

    if (tree1 != NULL && tree2 != NULL && tree1->value == tree2->value) {
        return isEqual(tree1->left, tree2->left) && isEqual(tree1->right, tree2->right);
    }
    
    return false;
}

// verifica se a primeira árvore binaria é subconjunto da segunda
bool subset(Node * root1, Node * root2) {
    if(isEqual(root1, root2)) return false;

    Node * pointer_for_root1_in_root2 = find(root2, root1->value);

    if(pointer_for_root1_in_root2 == NULL) return false;

    if(isEqual(pointer_for_root1_in_root2, root1)) return true;

    return false;
}

// verifica se primeira árvore binaria é subconjunto próprio da segunda
bool subset_equal(Node * root1, Node * root2) {
    Node * pointer_for_root1_in_root2 = find(root2, root1->value);

    if(pointer_for_root1_in_root2 == NULL) return false;

    if(isEqual(pointer_for_root1_in_root2, root1)) return true;

    return false;
}

bool union_trees(Node * root1, Node * root2) {
    if(root1 == NULL || root2 == NULL || find(root1, root2->value) == NULL) return false;

    Node * pointertoroot = find(root1, root2->value);

    pointertoroot = root2;
    return true;
}

int main () {
    Node * tree1 = createTree('A');
    Node * tree2 = createTree('O');
    Node * tree3 = createTree('A');

    //tree1
    insert(tree1, 'B', 'A');
    insert(tree1, 'C', 'A');
    insert(tree1, 'D', 'B');

    print_tree(tree1);
    printf("\n");

    insert(tree1, 'E', 'B');

    print_tree(tree1);
    printf("\n");

    //tree2
    insert(tree2, 'I', 'O');
    insert(tree2, 'E', 'O');

    //print_tree(tree2);
    //printf("\n");

    //tree3
    insert(tree3, 'B', 'A');
    insert(tree3, 'D', 'B');

    printf("%d\n", isEqual(tree1, tree3) ? 1 : 0);

    insert(tree3, 'F', 'B');

    printf("%d\n", isEqual(tree1, tree3) ? 1 : 0);

    print_tree(tree1);
    printf("\n");
    
    printf("%d\n", union_trees(tree1, tree3));

    print_tree(tree1);
    printf("\n");
}
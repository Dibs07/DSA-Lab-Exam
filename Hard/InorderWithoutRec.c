#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct BinaryTree
{
    int data;
    struct BinaryTree *left, *right;
} Tree;
typedef struct stack
{
    Tree *s;
    struct stack *next;
} stack;
struct stack *head = NULL;
void push(Tree *t)
{
    stack *ptr = (stack *)malloc(sizeof(stack));
    if (ptr == NULL)
    {
        printf("Overflow\n");
    }
    ptr->s = t;
    ptr->next = head;
    head = ptr;
}

Tree *pop()
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return 0;
    }
    stack *temp = head;
    head = head->next;
    Tree *t = temp->s;
    free(temp);
    return t;
}

Tree *createTree(int data)
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void inOrder(Tree *root)
{
    Tree *curr = root;
    bool done = 0;
    if (root == NULL)
    {
        return;
    }
    while (!done)
    {
        if (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }
        else
        {
            if (head != NULL)
            {
                curr = pop();
                printf("%d ", curr->data);
                curr = curr->right;
            }
            else
                done = 1;
        }
    }
}

int main()
{

    Tree *root = createTree(10);
    root->left = createTree(5);
    root->left->right = createTree(8);
    root->right = createTree(20);
    root->right->left = createTree(3);
    root->right->right = createTree(4);

    inOrder(root);
}

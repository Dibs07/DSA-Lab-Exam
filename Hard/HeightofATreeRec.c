#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct BinaryTree
{
    int data;
    struct BinaryTree *left, *right;
} Tree;

Tree *createTree(int data)
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int HeightOfABT(Tree *root)
{
    if(root==NULL){
        return 0;
    }
    else{
        int lh=HeightOfABT(root->left);
        int rh=HeightOfABT(root->right);
        if(lh>rh)
            return 1+lh;
        else
            return 1+rh;
    }
}

int main()
{

    Tree *root = createTree(10);
    root->left = createTree(5);
    root->left->right = createTree(8);
    root->left->right->left = createTree(8);
    root->left->right->left->right = createTree(8);
    root->right = createTree(20);
    root->right->left = createTree(3);
    root->right->right = createTree(4);

    
    printf("Height of the tree: %d",HeightOfABT(root));
}

#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node * tree;
typedef struct tree_node {
    int data;
    tree left;
    tree right;
} ;

typedef struct StackNode {
    tree node;
    struct StackNode* next;
} *Stack;

typedef struct QueueNode {
    tree node;
    struct QueueNode* next;
} *Queue;

void preorderTraversal(tree root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(tree root){
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ",root->data);
}

void inorderTraversal(tree root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

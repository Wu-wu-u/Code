#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
     if (inorderSize == 0) {
        return NULL;
    }
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    
    int rootIndex = 0;
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == root->val) {
            rootIndex = i;
            break;
        }
    }
    
    root->left = buildTree(inorder, rootIndex, postorder, rootIndex);
    root->right = buildTree(inorder + rootIndex + 1, inorderSize - rootIndex - 1, postorder + rootIndex, postorderSize - rootIndex - 1);
    
    return root;
}

void printZigzag(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct TreeNode** stack1 = malloc(sizeof(struct TreeNode*) * 1000);
    struct TreeNode** stack2 = malloc(sizeof(struct TreeNode*) * 1000);
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    int leftToRight = 0;

    while (top1 != -1 || top2 != -1) {
        while (top1 != -1) {
            struct TreeNode* node = stack1[top1--];
            printf("%d ", node->val);
            if (leftToRight) {
                if (node->left) stack2[++top2] = node->left;
                if (node->right) stack2[++top2] = node->right;
            } else {
                if (node->right) stack2[++top2] = node->right;
                if (node->left) stack2[++top2] = node->left;
            }
        }
        struct TreeNode** temp = stack1;
        stack1 = stack2;
        stack2 = temp;
        int tempTop = top1;
        top1 = top2;
        top2 = tempTop;
        leftToRight = !leftToRight;
    }

    free(stack1);
    free(stack2);
}

int main(){
    int n;
    struct TreeNode* T;
    int post[40],inorder[40];
    memset(post,0,sizeof(post)/sizeof(int));memset(inorder,0,sizeof(inorder)/sizeof(int));
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    for (int i=0;i<n;i++){
        scanf("%d",&post[i]);
    }
    T = buildTree(inorder, n, post, n);
    printZigzag(T);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

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
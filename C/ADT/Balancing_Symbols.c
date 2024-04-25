#include <stdio.h>
#include <stdlib.h>

// 栈的节点
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// 创建一个新的节点
Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// 将元素压入栈
void push(Node** top, char data) {
    Node* node = newNode(data);
    node->next = *top;
    *top = node;
}

// 从栈中弹出元素
char pop(Node** top) {
    if (*top == NULL) {
        return '\0';
    }
    Node* temp = *top;
    *top = (*top)->next;
    char popped = temp->data;
    free(temp);

    return popped;
}

// 检查栈是否为空
int isEmpty(Node* top) {
    return top == NULL;
}

// 检查括号是否匹配
int isMatchingPair(char character1, char character2) {
    return character1 == '(' && character2 == ')';
}

// 检查括号是否平衡
int areParenthesisBalanced(char exp[]) {
    Node* stack = NULL;

    for (int i = 0; exp[i]; ++i) {
        if (exp[i] == '(') {
            push(&stack, exp[i]);
        }
        else if (exp[i] == ')') {
            if (isEmpty(stack) || !isMatchingPair(pop(&stack), exp[i])) {
                return 0;
            }
        }
    }

    if (isEmpty(stack)) {
        return 1;  // balanced
    }
    else {
        return 0;  // not balanced
    }
}

int main() {
    char exp[] = "((()))()";

    if (areParenthesisBalanced(exp)) {
        printf("Balanced \n");
    }
    else {
        printf("Not Balanced \n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Queue {
    Node* data;
    struct Queue* next;
} Queue;

Queue* createQueue(Node* data) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = data;
    queue->next = NULL;
    return queue;
}

void enqueue(Queue** queue, Node* data) {
    Queue* newQueue = createQueue(data);
    if (!*queue) {
        *queue = newQueue;
        return;
    }
    Queue* temp = *queue;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newQueue;
}

Node* dequeue(Queue** queue) {
    if (!*queue) {
        return NULL;
    }
    Queue* temp = *queue;
    *queue = (*queue)->next;
    Node* data = temp->data;
    free(temp);
    return data;
}

void levelOrderTraversal(Node* root) {
    Queue* queue = NULL;
    enqueue(&queue, root);
    while (queue) {
        Node* temp = dequeue(&queue);
        printf("%d ", temp->data);
        if (temp->left) {
            enqueue(&queue, temp->left);
        }
        if (temp->right) {
            enqueue(&queue, temp->right);
        }
    }
}
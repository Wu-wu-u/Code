#include <stdio.h>
#include <stdlib.h>

// 队列的节点
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 队列
typedef struct Queue {
    Node *front, *rear;
} Queue;

// 创建一个新的节点
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// 创建一个空的队列
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 添加元素到队列
void enqueue(Queue* q, int data) {
    Node* temp = newNode(data);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// 从队列中移除元素
void dequeue(Queue* q) {
    if (q->front == NULL)
        return;

    Node* temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    dequeue(q);
    printf("Queue Front : %d \n", q->front->data);
    printf("Queue Rear : %d", q->rear->data);
}
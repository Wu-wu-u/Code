#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int  compare(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}



Node* createNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

void insert(Node* root,int data){
    if(root==NULL) root=createNode(data);
    else if(data<root->data) insert(root->left,data);
    else insert(root->right,data);
}

int Min(int a,int b){
    return a<b?a:b;
}

Node* build_tree(Node* root, int *a, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int n = end - start + 1;
    int h = log2(n + 1);
    int maxlevel = pow(2, h);
    int actual= n - (maxlevel - 1);
    int min=Min(actual,maxlevel/2);
    int leftTreeSize = min + maxlevel / 2 - 1;

    Node *node = createNode(a[start + leftTreeSize]);

    node->left = build_tree(root, a, start, start + leftTreeSize - 1);
    node->right = build_tree(root, a, start + leftTreeSize + 1, end);

    return node;

}

void inorderTraversal(Node* root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);}

/*-----------------------------------*/
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
    int i=0;
    while (queue) {
        Node* temp = dequeue(&queue);
        if(i++==0) printf("%d", temp->data);
        else printf(" %d", temp->data);
        
        if (temp->left) {
            enqueue(&queue, temp->left);
        }
        if (temp->right) {
            enqueue(&queue, temp->right);
        }
    }
}
/*---------------------------------------*/

int main() {
    int n;
    scanf("%d", &n);
    int *a;
    a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);

    Node* root = NULL;
    root = build_tree(root, a, 0, n - 1);
    levelOrderTraversal(root);
    //inorderTraversal(root);
    //preorderTraversal(root);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int *disc, *low, *parent, *visited;
int time = 0;

typedef struct Edge {
    int u, v;
} Edge;
//存放边到栈里面

typedef struct Stack {
    Edge edges[100];
    int top;
} Stack;

void push(Stack *stack, int u, int v) {
    stack->edges[stack->top].u = u;
    stack->edges[stack->top].v = v;
    stack->top++;
}

Edge pop(Stack *stack) {
    stack->top--;
    return stack->edges[stack->top];
}




void dfs(int u, int adj[][100], int V, Stack *stack) {
    disc[u] = low[u] = ++time; //用time和disc[]数组记录访问的顺序，low[]数组记录u或u的子树能够追溯到的最早的栈中节点的次序
    visited[u] = 1;
    int children = 0;
    for (int v = 0; v < V; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                push(stack, u, v);
                dfs(v, adj, V, stack);
                low[u] = MIN(low[u], low[v]);
                if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u])) { //如果u是根节点且有两个以上的子树，或者u不是根节点且v是u的子树能够追溯到的最早的栈中节点的次序大于等于u的访问次序
                    printf("Biconnected Component:\n");
                    int set[100]={0};
                    set[u]++;
                    while (stack->edges[stack->top - 1].u != u || stack->edges[stack->top - 1].v != v) {
                        set[stack->edges[stack->top - 1].u]++;
                        set[stack->edges[stack->top - 1].v]++;
                        //printf("%d -- %d\n", stack->edges[stack->top - 1].u, stack->edges[stack->top - 1].v);
                        pop(stack);
                    }
                    //printf("%d -- %d\n", stack->edges[stack->top - 1].u, stack->edges[stack->top - 1].v);
                    set[stack->edges[stack->top - 1].u]++;
                    set[stack->edges[stack->top - 1].v]++;
                    pop(stack);
                    for(int i=0;i<100;i++){
                        if(set[i]>0) printf("%d ",i);
                    }
                    printf("\n");
                }
            } else if (v != parent[u] && disc[v] < low[u]) {//对于访问过的邻节点，其实就是back edge，更新low[u]
                low[u] = disc[v];
                push(stack, u, v);
            }
        }
    }
}

void findBiconnectedComponents(int adj[][100], int V) {
    disc = (int *)malloc(V * sizeof(int));
    low = (int *)malloc(V * sizeof(int));
    parent = (int *)malloc(V * sizeof(int));
    visited = (int *)malloc(V * sizeof(int));
    Stack stack;
    stack.top = 0;
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, V, &stack);
            if (stack.top != 0) {
                printf("Biconnected Component:\n");
                int set[100]={0};
                while (stack.top != 0) {
                    set[stack.edges[stack.top - 1].u]++;
                    set[stack.edges[stack.top - 1].v]++;
                    //printf("%d -- %d\n", stack.edges[stack.top - 1].u, stack.edges[stack.top - 1].v);
                    pop(&stack);
                }
                for (int i = 0; i < 100; i++) {
                    if (set[i] > 0) printf("%d ", i);
                }
                printf("\n");
            }
        }
    }
}

int main() {
    int adj[100][100] = {0};
    int V = 5;
    adj[1][0] = adj[0][1] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[3][4] = adj[4][3] = 1;
    findBiconnectedComponents(adj, V);
    return 0;
}
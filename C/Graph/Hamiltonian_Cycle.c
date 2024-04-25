//无向哈密顿回路
//必须为环，即路径起末为相同顶点；同时恰经过所有顶点一次

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200

int graph[MAXN][MAXN];
int visited[MAXN];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    memset(graph, 0, sizeof(graph));

    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1-1][v2-1] = graph[v2-1][v1-1] = 1; //无向图
    }

    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int n;
        scanf("%d", &n);
        int *path = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &path[j]);
            path[j]--;  // Convert to 0-based index
        }

        if (n != N + 1 || path[0] != path[n-1]) {
            printf("NO\n");
        } else {
            memset(visited, 0, sizeof(visited));
            int j;
            for (j = 0; j < n - 1; j++) {
                if (visited[path[j]] || !graph[path[j]][path[j+1]]) { //检查是否有经过重复的顶点，同时检查相邻顶点是否有边
                    printf("NO\n");
                    break;
                }
                visited[path[j]] = 1;
            }
            if (j == n - 1) {
                printf("YES\n");
            }
        }

        free(path);
    }

    return 0;
}
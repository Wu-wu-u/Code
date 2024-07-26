#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <fstream> // 添加这一行

#include <queue>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10;
const ll INF = 1ll<<62;
vector<int>e[MAXN];
vector<int>w[MAXN];
bool vis[MAXN];
ll d[MAXN];
int pre[MAXN];
int n;

struct Node {
	ll d;
	int u;
	bool operator < (const Node & rhs) const {
		return d > rhs.d;
	}
};

void Dijkstra() {
	priority_queue<Node>q;
	for( int i=1; i<=n; i++ ) d[i] = INF;
	d[1] = 0;
	memset(vis, 0, sizeof(vis));
	Node tn;
	tn.d = 0, tn.u = 1;
	q.push(tn);
	while(!q.empty()) {
		Node t = q.top();
		q.pop();
		int u = t.u;
		if(vis[u]) continue;
		vis[u] = true;
		for( int i=0; i<e[u].size(); i++ ) {
			int v = e[u][i];
			if(d[v] > d[u] + w[u][i]) {
				d[v] = d[u] + w[u][i];
				pre[v] = u;
				tn.d = d[v], tn.u = v;
				q.push(tn);
			}
		}
	}
}

int main() {
    ifstream file("graph.txt"); // 使用ifstream打开文件
    int m;
    while(file >> n >> m) { // 从文件中读取数据
        for( int i=1; i<=n; i++ ) e[i].clear(), w[i].clear();
        int a, b, c;
        for( int i=0; i<m; i++ ) {
            file >> a >> b >> c; // 从文件中读取数据
            e[a].push_back(b);
            w[a].push_back(c);
            e[b].push_back(a);
            w[b].push_back(c);
        }
        Dijkstra();
        if(d[n] == INF) printf("-1\n");
        else {
            e[1].clear();
            e[1].push_back(n);
            while(pre[n] != 1) {
                n = pre[n];
                e[1].push_back(n);
            }
            e[1].push_back(1);
            for( int i=e[1].size()-1; i>0; i-- ) printf("%d ", e[1][i]);
            printf("%d\n", e[1][0]);
        }
    }
    file.close(); // 关闭文件
    return 0;
}
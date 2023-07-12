#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

const int MAXN = 1000;
const int INF = 1e9;
int capacity[MAXN][MAXN] = {0};
bool visited[MAXN] = {0};
int parent[MAXN] = {0};
int n, m;
vector<vector<int>> adj(MAXN);

void bfs(){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (!visited[v] && capacity[u][v] > 0){
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back(b);
        capacity[a][b] = c;
    }
    int maxflow = 0;
    while (1){
        memset(visited, false, sizeof(visited));
        bfs();
        if (!visited[n]) break;
        int path = INF;
        for (int v = n; v != 1; v = parent[v]){
            int u = parent[v];
            path = min(path, capacity[u][v]);
        }
        for (int v = n; v != 1; v = parent[v]){
            int u = parent[v];
            capacity[u][v] -= path;
            capacity[v][u] += path;
        }
        maxflow += path;
    }
    cout << maxflow;
}
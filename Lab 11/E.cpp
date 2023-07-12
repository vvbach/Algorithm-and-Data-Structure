#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void DFS(int u, vector<vector<int>> &graph, vector<int>& visited, vector<int>& topsort){
    visited[u] = 1;
    for (auto i : graph[u]){
        if (!visited[i]){
            DFS(i, graph, visited, topsort);
        }
    }
    topsort.push_back(u);
}

int main(){
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t;
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, 0);
    vector<int> topsort;
    vector<int> dist(n + 1, INF);
    vector<vector<int>> edge(n + 1, vector<int>(n + 1));
    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        graph[a].push_back(b);
        edge[a][b] = c;
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            DFS(i, graph, visited, topsort);
        }
    }
    dist[s] = 0;
    reverse(topsort.begin(), topsort.end());
    for (int i = 0; i < n; i++){
        for (auto v : graph[topsort[i]]){
            if (dist[v] > dist[topsort[i]] + edge[topsort[i]][v]) dist[v] = dist[topsort[i]] + edge[topsort[i]][v];
        }
    }
    cout << (dist[t] == INF ? -1 : dist[t]);
}
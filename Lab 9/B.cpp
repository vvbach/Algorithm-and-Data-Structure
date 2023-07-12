#include <iostream>
#include <vector>
using namespace std;

bool ans = false;

void DFS(int u, int p, vector<vector<int>> &graph, vector<bool>& visited){
    visited[u] = 1;
    for (auto i : graph[u]){
        if (i == p) continue;
        if (!visited[i]){
            DFS(i, u, graph, visited);
        }
        else {
            ans = true;
        }
    }

}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, 0);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);  
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        if (ans) break;
        if (!visited[i]){
            DFS(i, 0, graph, visited);
        }
    }
    cout << (ans ? "YES" : "NO");
}   
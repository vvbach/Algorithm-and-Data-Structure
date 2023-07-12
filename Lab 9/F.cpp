#include <iostream>
#include <vector>
using namespace std;

bool ans = true;

void DFS(int u, int p, vector<vector<int>> &graph, vector<bool>& visited){
    visited[u] = 1;
    for (auto i : graph[u]){
        if (i == p) continue;
        if (!visited[i]){
            DFS(i, u, graph, visited);
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, 0);
    vector<int> deg(n + 1, 0);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);  
        graph[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int num_of_component = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            num_of_component++;
            DFS(i, 0, graph, visited);
        }
    }
    if (num_of_component > 1) ans = false;
    else {
        int v_1 = 0;
        int v_2 = 0;
        for (int i = 1; i <= n; i++){
            if (deg[i] > 2) {
                ans = false;
                break;
            }
            if (deg[i] == 1) v_1++;
            else if (deg[i] == 2) v_2++;
        }
        if (v_1 == 2 && v_2 == n - 2) ans = true;
    }
    cout << (ans ? "YES" : "NO");
}   
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

void DFS(int u, vector<vector<int>> &graph, vector<int>& component, int count){
    component[u] = count;
    for (auto i : graph[u]){
        if (!component[i]){
            DFS(i, graph, component, count);
        }
    }
}

void removeEdge(int u, int v, vector<vector<int>> &graph) {
    auto it = find(graph[u].begin(), graph[u].end(), v);
    graph[u].erase(it);
    it = find(graph[v].begin(), graph[v].end(), u);
    graph[v].erase(it);
}

int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> graph(n + 1);
    vector<int> component(n + 1, 0);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);  
        graph[b].push_back(a);
    }
    int count = 1;
    for (int i = 1; i <= n; i++){
        if (!component[i]) {
            DFS(i, graph, component, count);
            count++;
        }
    }
    char c;
    for (int i = 0; i < q; i++){
        cin >> c >> a >> b;
        if (c == '?'){
            if (component[a] == component[b]) cout << "YES" << endl;
            else cout << "NO" << endl;
        } 
        else {
            removeEdge(a, b, graph);
            fill(component.begin(), component.end(), 0);
            count = 1;
            for (int i = 1; i <= n; i++){
                if (!component[i]) {
                    DFS(i, graph, component, count);
                    count++;
                }
            }
        }
    }
}
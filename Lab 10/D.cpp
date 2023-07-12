#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int u, vector<vector<int>> &graph, vector<int>& visited, vector<int>& ans){
    visited[u] = 1;
    for (auto i : graph[u]){
        if (!visited[i]){
            DFS(i, graph, visited, ans);
        }
    }
    ans.push_back(u);
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, 0);
    vector<int> ans;
    vector<int> index(n + 1);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++){
        index.push_back(i);
        if (!visited[i]){
            DFS(i, graph, visited, ans);
        }
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());
    for (int i = 1; i <= n; i++){
        index[ans[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        cout << index[i] << " ";
    }
}
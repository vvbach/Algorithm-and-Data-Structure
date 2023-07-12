#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> st;

void DFS(int u, vector<vector<int>> &graph, vector<int> &visited){  
    visited[u] = 1;
    for (auto i : graph[u]){
        if (!visited[i]){
            DFS(i, graph, visited);
        }
    }
    st.push(u);
}

void DFS2(int u, vector<vector<int>> &graph, vector<int> &component, int count){
    component[u] = count;
     for (auto i : graph[u]){
        if (!component[i]){
            DFS2(i, graph, component, count);
        }
    }
}

int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> reversed_graph(n + 1);
    vector<int> visited(n + 1, 0);
    vector<int> component(n + 1, 0);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        reversed_graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]) DFS(i, graph, visited);
    }
    int count = 1;
    while (!st.empty())
    {
        int i = st.top();
        st.pop();
        if (!component[i]) {
            DFS2(i, reversed_graph, component, count);
            count++;
        }
    }
    

    for (int i = 0; i < q; i++){
        cin >> a >> b;
        cout << ((component[a] == component[b]) ? "YES" : "NO") << endl;
    }
}
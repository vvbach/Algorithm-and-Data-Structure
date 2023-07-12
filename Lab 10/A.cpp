#include <iostream>
#include <vector>

using namespace std;

void DFS(int u, int p, vector<vector<int>> &graph, vector<int> &component, int num){
    component[u] = num;
    for (auto i : graph[u]){
        if (i == p) continue;
        if (!component[i]){
            DFS(i, u, graph, component, num);
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> component(n + 1, 0);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int num = 0;
    for (int i = 1; i <= n; i++){
        if (!component[i]){
            num++;
            DFS(i, 0, graph, component, num);
        }
    }
    vector<bool> trap(num + 1, 0);
    int t;
    for (int i = 1; i <= n; i++){
        cin >> t;
        if (t == 1){
            trap[component[i]] = 1;
        }
    }
    cout << num << endl;
    for (int i = 1; i <= n; i++){
        cout << component[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= num; i++){
        cout << trap[i] << " ";
    }
}
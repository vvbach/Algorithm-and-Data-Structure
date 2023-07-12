#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int s, vector<vector<int>> &graph, vector<int> &distance){
    queue<int> q;
    q.push(s);
    distance[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : graph[u]){
            if(distance[i] == 100000){
                distance[i] = distance[u] + 1;
                q.push(i);
            }
        }
    }    
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> distance(n + 1, 100000); // INF
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int s, f; cin >> s >> f;
    BFS(s, graph, distance);
    cout << (distance[f] == 100000 ? -1 : distance[f]);
}
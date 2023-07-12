#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
struct Edge{
    int v;
    int w;
};
struct Node{
    int u;
    int Dist_u;
};
struct cmp{
    bool operator() (Node a, Node b) {
        return a.Dist_u > b.Dist_u;
    }
};

int main(){
    int n, m, q, s; cin >> n >> m >> q >> s;
    vector<vector<Edge>> edge(n + 1);
    vector<int> d(n + 1, INF);
    vector<bool> P(n + 1, 0);

    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    d[s] = 0;
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({s, d[s]});
    while (!pq.empty()){
        int u = pq.top().u;
        pq.pop();
        if(P[u] == true) 
            continue;
            
        P[u] = true;
        for (auto e : edge[u]){
            if (d[e.v] > d[u] + e.w){
                d[e.v] = d[u] + e.w;
                pq.push({e.v, d[e.v]});
            }
        }
    }
    for (int i = 0; i < q; i++){
        cin >> a;
        cout << (d[a] == INF ? -1 : d[a]) << endl;
    }
}
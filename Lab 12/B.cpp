#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> parent(100001);
vector<int> sz(100001);

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) return v; 
    int p = find_set(parent[v]); 
    parent[v] = p; 
    return p;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b); 
        parent[b] = a;
        sz[a] += sz[b]; 
    } 
}

int main(){
    vector<Edge> edges;
    int n, m; cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    for (int i = 1; i <= n; i++){
        make_set(i);
    }
    sort(edges.begin(), edges.end(), cmp);
    long long int ans = 0;
    for (auto e : edges){
        if (find_set(e.u) != find_set(e.v)){
            union_sets(e.u, e.v);
            ans += e.w;
        }
    }
    cout << ans;
}
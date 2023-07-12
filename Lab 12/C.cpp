#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


vector<int> parent(200001);
vector<int> sz(200001);
vector<bool> present;
vector<vector<pair<int, int>>> adj(200001, vector<pair<int, int>>());

struct Edge {
    int u, v, w;
};

bool cmp(pair<int, Edge> a, pair<int, Edge> b){
    return a.second.w < b.second.w;
}

void make_set(int n){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = i;
    }
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

int up[200001][19];
int depth[200001];
int weightWithParent[200001];
void dfs(int u, int p, int d){
    depth[u] = d;
    up[u][0] = p;
    for (int i = 1; i <= 18; i++){
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (auto v : adj[u]){
        if (v.first != p){
            weightWithParent[v.first] = v.second; 
            dfs(v.first, u, d+1);
        }
    }
}

int lca(int u, int v){
    if (depth[u] != depth[v]){
        if (depth[u] < depth[v]){
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for (int i = 0; (1 << i) <= diff; i++){
            if (diff >> i & 1) u = up[u][i];
        }
    }
    if (u == v) return u;

    int k =  ceil(log2(depth[u]));
    for (int i = k; i >= 0; i--){
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        } 
    }
    return up[u][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int, Edge>> edges;
    vector<Edge> list;
    int n, m; cin >> n >> m;
    vector<int> res(m);
    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edges.push_back({i, {a, b, c}});
        list.push_back({a, b, c});
        present.push_back(false);
    }
    sort(edges.begin(), edges.end(), cmp);
    int basicMST = 0;
    make_set(n);
    for (auto e : edges){
        if (find_set(e.second.u) != find_set(e.second.v)){
            union_sets(e.second.u, e.second.v);
            basicMST += e.second.w;
            present[e.first] = true;
            adj[e.second.u].push_back({e.second.v, e.second.w});
            adj[e.second.v].push_back({e.second.u, e.second.w});
        }
    }
    dfs(1, 1, 0);
    for (int i = 0; i < m; i++){
        if (present[i]) res[i] = basicMST;
        else {
            int max_u = 0;
            int max_v = 0;
            int u = list[i].u;
            int v = list[i].v;
            int p = lca(u, v);
            while (u != p){
                max_u = max(max_u, weightWithParent[u]);
                u = up[u][0];
            }
            while (v != p){
                max_v = max(max_v, weightWithParent[v]);
                v = up[v][0];
            }
            res[i] = basicMST + list[i].w - ((max_u > max_v) ? max_u : max_v);
        }
    }
   for(auto i : res) cout << i << endl;
}
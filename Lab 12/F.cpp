#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
struct Edge {
    int u, v, w;
};

vector<int> parent(100001);
vector<int> sz(100001);
vector<int> present;
vector<Edge> edges;


bool cmp(Edge a, Edge b){
    return a.w < b.w;
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

int union_sets_1(int i, int sum) {
    int a = find_set(edges[i].u);
    int b = find_set(edges[i].v);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b); 
        parent[b] = a;
        sz[a] += sz[b]; 
        sum += edges[i].w;
        present.push_back(i);
    } 
    return sum;
}


int union_sets_2(int i, int sum, int &edg) {
    int a = find_set(edges[i].u);
    int b = find_set(edges[i].v);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b); 
        parent[b] = a;
        sz[a] += sz[b]; 
        sum += edges[i].w;
        edg++;
    } 
    return sum;
}

int main(){
    int n, m; cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    make_set(n);
    sort(edges.begin(), edges.end(), cmp);
    int sum_1 = 0;
    for (int i = 0; i < m; i++){
        sum_1 = union_sets_1(i, sum_1);
    }

    int sum = 0;
    int sum_2 = INT_MAX;
    for (int i = 0; i < present.size(); i++){
        make_set(n);
        int edg = 0;
        for (int j = 0; j < m; j++){
            if (j == present[i]) continue;
            sum = union_sets_2(j, sum, edg);
        }
        if (edg != n - 1) {
            sum = 0;
            continue;
        }
        if (sum_2 > sum) sum_2 = sum;
        sum = 0;
    }
    cout << sum_1 << " " << sum_2;
}
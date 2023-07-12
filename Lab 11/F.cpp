#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Query {
    int a, b;
    char c;
};

vector<int> parent(100001);
vector<int> sz(100001);

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
    int n, m, q;
    cin >> n >> m >> q;
    int a, b;
    char c;
    vector<Query> query(q);
    set<pair<int, int>> edge;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        if (b < a) swap(a, b);
        edge.insert({a, b});
    }
    for (int i = 0; i < q; i++){
        cin >> c >> a >> b;
        if (b < a) swap(a, b);
        if (c == '-'){
            edge.erase({a, b});
        }
        Query qr;
        qr.a = a;
        qr.b = b;
        qr.c = c;
        query.push_back(qr);
    }
    for (int i = 1; i <= n; i++){
        make_set(i);
    }
    for (auto i : edge){
        union_sets(i.first, i.second);
    }
    vector<bool> ans;
    for (int i = query.size() - 1; i >= 0; i--){
        if (query[i].c == '?'){
            ans.push_back(find_set(query[i].a) == find_set(query[i].b));
        }
        else {
            union_sets(query[i].a, query[i].b);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--){
        cout << (ans[i] ? "YES" : "NO") << endl;
    }
}
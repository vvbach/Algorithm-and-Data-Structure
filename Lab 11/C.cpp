#include<iostream>
#include<vector>

using namespace std;

const long long int INF = 10e12;

struct Edge {
    int start, end, w;
};   

int Bellman_Ford(vector<Edge> &E,int n, int source){
    vector<long long> d(n + 1, INF);
    vector<int> trace(n + 1);
    d[source] = 0;
    bool change;
    for(int T = 1; T < n; T++){   
        change = false;
        for (auto e : E){
            if (d[e.start] != INF && d[e.end] > d[e.start] + e.w){
                trace[e.end] = e.start;
                d[e.end] = d[e.start] + e.w;
                change = true;
            } 
        }
        if (!change) break;
    }
    //run again to find a neg cycle
    int negStart = 0;
    for (auto e : E){
        if (d[e.start] != INF && d[e.end] > d[e.start] + e.w){
            trace[e.end] = e.start;
            d[e.end] = -INF;
            negStart = e.end;
        }
    }
    if (!negStart) return 0;
    
    int u = negStart;
    for (int i = 0; i < n; i++) {
        u = trace[u]; 
    }

    vector<int>negCycle (1, u);
    for (int v = trace[u]; v != u; v = trace[v]) {
        negCycle.push_back(v);
    }
    return negCycle.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, k; cin >> N >> k;
    for (int graph = 0; graph < N; graph++){
        int n, m; cin >> n >> m;
        vector<Edge> E;
        int a, b, c;
        int source;
        for (int i = 0; i < n; i++){
            cin >> a >> b >> c;
            if (i == 0) source = a;
            E.push_back({a, b, c});
        }
        int ans = Bellman_Ford(E, n, source);
        cout << ((ans == 0 || ans < k) ? "YES" : "NO") << endl; 
    }
}
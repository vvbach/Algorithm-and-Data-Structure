#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floyd_warshall(int n, vector<vector<int>> &dist) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    int a, b, c;
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        dist[a][b] = dist[b][a] = c;
    }
    floyd_warshall(n, dist);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] != INF) ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
    return 0;
}
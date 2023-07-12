#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floyd_warshall(int n, vector<vector<int>> &dist, int gap) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            if (abs(i - k) > gap) continue;
            for(int j = 1; j <= n; j++) {
                if(abs(j - k) > gap) continue;
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    int a, b, c;
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back(b);
        dist[a][b] = c;
    }
    floyd_warshall(n, dist, k);
    int q; cin >> q;
    for (int i = 0; i < q; i++){
        cin >> a >> b;
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << endl;
    }
    return 0;
}
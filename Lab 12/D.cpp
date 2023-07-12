#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool graph[101][101] = {0};
vector<vector<int>> adj(10001);
bool visited[10001] = {0};
int n, m, q;
int matching[10001] = {0};
vector<int> leftSide;

int moveX[] = {0, 0, -1, 1};
int moveY[] = {-1, 1, 0, 0};

bool dfs(int u){
    if (visited[u]) return false;
    visited[u] = true;
    for (auto v : adj[u]){
        if (matching[v] == 0 || dfs(matching[v])){
            matching[v] = u;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> q;
    int a, b;
    for (int i = 0; i < q; i++){
        cin >> a >> b;
        graph[a][b] = 1;
    }
    bool left;
    for (int i = 1; i <= n; i++){
        if (i % 2 == 1) left = 1;
        else left = 0;
        for (int j = 1; j <= m; j++){
            if (graph[i][j]) {
                left = !left;
                continue;
            }
            if (left) leftSide.push_back((i - 1) * m + j);
            left = !left;
            for(int k = 0; k < 4; k++){
                int x = i + moveX[k];
                int y = j + moveY[k];
                if (x > n || x < 1) continue;
                if (y > m || y < 1) continue;
                if (graph[x][y]) continue;
                adj[(i - 1) * m + j].push_back((x - 1) * m + y);
            }
        }
    }
    for (auto i : leftSide){
        memset(visited, false, sizeof(visited));
        dfs(i);
    }
    
    for (int i = 1; i <= n * m; i++){
        matching[matching[i]] = i;
    }
    int count = 0;
    for (int i = 1; i <= n * m; i++){
        if (matching[i] != 0) count++;
    }
    cout << count;
}

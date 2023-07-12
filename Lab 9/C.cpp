#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void BFS(int &x_pos, int &y_pos, int &n, int &m, vector<vector<char>> &matrix, vector<vector<bool>> &visited){
    queue<pair<int, int>> q;
    q.push({x_pos, y_pos});
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int u = x + moveX[i];
            int v = y + moveY[i];
            if (u >= n || u < 0) continue;
            if (v >= m || v < 0) continue;

            if (matrix[u][v] == '.' && !visited[u][v]){
                visited[u][v] = true;
                q.push({u, v});
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (matrix[i][j] == '.' && !visited[i][j]){
                count++;
                BFS(i, j, n, m, matrix, visited);
            }
        }
    }
    cout << count;
}
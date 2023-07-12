#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int moveX[] = {0, 0, -1, 1};
int moveY[] = {-1, 1, 0, 0};

struct Point {
    int x, y, l, r;
};

int BFS(Point& src, int &n, int &m, vector<vector<char>> &matrix, vector<vector<bool>> &visited){
    queue<Point> q;
    q.push(src);
    visited[src.x][src.y] = 1;
    int count = 1;
    while (!q.empty()){
        Point p = q.front();
        int x = p.x;
        int y = p.y;
        q.pop();
        for (int i = 0; i < 4; i++){
            if (i == 0 && p.l <= 0) continue;
            if (i == 1 && p.r <= 0) continue;
            int u = x + moveX[i];
            int v = y + moveY[i];
            if (u >= n || u < 0) continue;
            if (v >= m || v < 0) continue;

            if (matrix[u][v] == '.' && !visited[u][v]){
                visited[u][v] = true;
                if (i == 0) q.push({u, v, p.l - 1, p.r});
                else if (i == 1) q.push({u, v, p.l, p.r - 1});
                else q.push({u, v, p.l, p.r});
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n, m; cin >> n >> m;
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<vector<char>> matrix(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    int count = 0;
    Point src;
    src.x = x;
    src.y = y;
    src.l = l;
    src.r = r;
    cout << BFS(src, n, m, matrix, visited);
}
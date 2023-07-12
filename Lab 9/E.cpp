#include <iostream>
#include <queue>

using namespace std;

struct Coordinate{
    int x, y, z;
};

int moveX[] = {-1, 1, 0, 0, 0, 0};
int moveY[] = {0, 0, -1, 1, 0, 0};
int moveZ[] = {0, 0, 0, 0, -1, 1};
bool visited[102][102][201] = {0};
int d[102][102][201] = {0};

void BFS(int x, int y, int z, int xf, int yf, int zf){
    queue<Coordinate> q;
    q.push({x, y, z});
    visited[x][y][z] = 1;
    while (!q.empty()){
        Coordinate c = q.front();
        q.pop();
        for (int i = 0; i < 6; i++){
            Coordinate c2 = {c.x + moveX[i], c.y + moveY[i], c.z + moveZ[i]};
            if (c2.x < 0 || c2.x > 101 || c2.y < 0 || c2.y > 101 || c2.z < 0 || c2.z > 200) continue;
            if (d[c2.x][c2.y][c2.z] >= 0 && !visited[c2.x][c2.y][c2.z]){
                visited[c2.x][c2.y][c2.z] = 1;
                d[c2.x][c2.y][c2.z] = d[c.x][c.y][c.z] + 1;
                q.push({c2.x, c2.y, c2.z});
            }
            if (c2.x == xf && c2.y == yf && c2.z == zf) return;
        }
    }
}

int main(){
    int k, e; cin >> k >> e;
    int xs, ys, zs, xf, yf, zf;
    cin >> xs >> ys >> zs >> xf >> yf >> zf;
    int x, y, z, h;
    for (int i = 0; i < k; i++){
        cin >> x >> y >> z >> h;
        for (int j = 0; j < h; j++){
            d[x][y][z + j] = -1;
            visited[x][y][z + j] = 1;
        }
    }
    d[xs][ys][zs] = 0;
    BFS(xs, ys, zs, xf, yf, zf);
    if (d[xf][yf][zf] > e || !visited[xf][yf][zf]) cout << -1;
    else cout << d[xf][yf][zf];
}
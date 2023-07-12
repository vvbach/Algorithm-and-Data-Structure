#include <iostream>
#include <vector>

typedef long long ll;

const int base = 10011;
const ll MOD = 1000000003;
const ll maxn = 1001;

using namespace std;

ll POW[maxn], hashArr[maxn][maxn];
ll arr[maxn][maxn];

ll getHash(int i, int j1, int j2) {
    return (hashArr[i][j2] - hashArr[i][j1 - 1] * POW[j2 - j1 + 1] + MOD * MOD) % MOD;
}


int main() {
    int n, m; cin >> n >> m;
    POW[0] = 1;
    for (int j = 1; j <= m; j++)
    	POW[j] = (POW[j - 1] * base) % MOD;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> arr[i][j];
            hashArr[i][j] = (hashArr[i][j - 1] * base + arr[i][j]) % MOD;
        }
    } 
    int q; cin >> q;
    int x1_1, y1_1, x2_1, y2_1, x1_2, y1_2, x2_2, y2_2;
    for (int _q = 0; _q < q; _q++){
        cin >> x1_1 >> y1_1 >> x2_1 >> y2_1;
        cin >> x1_2 >> y1_2 >> x2_2 >> y2_2;
        if (x2_1 - x1_1 != x2_2 - x1_2 || y2_1 - y1_1 != y2_2 - y1_2) cout << "NO" << endl;
        else {
            bool check = true;
            for (int i = 0; i <= x2_1 - x1_1; i++){
                if (getHash(x1_1 + i, y1_1, y2_1) != getHash(x1_2 + i, y1_2, y2_2)){
                    check = false;
                    break;
                }
            }
            if (check) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
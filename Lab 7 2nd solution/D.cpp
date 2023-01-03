#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(2, vector<int>(m, 0));
    char c;
    int max = 0;
    int x, y;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c;
            if (c == '1') dp[1][j] = 0;
            else {
                if (j == 0) dp[1][j] = 1;
                else dp[1][j] = min(min(dp[0][j], dp[1][j - 1]), dp[0][j - 1]) + 1;
            }
            if (dp[1][j] >= max){
                max = dp[1][j];
                x = i + 1 - max + 1;
                y = j + 1 - max + 1;
            }
        }
        for (int j = 0; j < m; j++){
            dp[0][j] = dp[1][j];
        }
    }
    cout << max << " " << x << " " << y;
}
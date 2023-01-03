#include <iostream>
using namespace std;

int dp[2][3000] = {0};
int min_val(int a, int b, int c){
    return min(min(a, b),c);
}

int main(){
    int n, m; cin >> n >> m;
    char x;
    int max = 0;
    int i_pos, j_pos;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> x;
            if (x == '1') dp[1][j] = 0;
            else {
                if (j == 0) dp[1][j] = 1;
                else dp[1][j] = min_val(dp[0][j], dp[1][j - 1], dp[0][j - 1]) + 1;
            }
            if (dp[1][j] >= max){
                max = dp[1][j];
                i_pos = i + 1;
                j_pos = j + 1;
            }
        }
        for (int j = 0; j < m; j++){
            dp[0][j] = dp[1][j];
        }
    }
    
    cout << max << " " << i_pos - max + 1 << " " << j_pos - max + 1;
}
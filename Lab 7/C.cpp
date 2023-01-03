#include <iostream>
using namespace std;

int dp[3000][3000];
int min_val(int a, int b, int c){
    return min(min(a, b),c);
}

int main(){
    int n, m; cin >> n >> m;
    char x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> x;
            if (x == '1') dp[i][j] = 0;
            else {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = min_val(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
            
        }
    }
    int max = 0;
    int i_pos, j_pos;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dp[i][j] >= max){
                max = dp[i][j];
                i_pos = i + 1;
                j_pos = j + 1;
            }
        }
    }
    cout << max << " " << i_pos - max + 1 << " " << j_pos - max + 1;
}
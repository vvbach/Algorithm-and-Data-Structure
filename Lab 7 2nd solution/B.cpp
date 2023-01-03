#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[301];
    int s, n; cin >> s >> n;
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= s; j++){
            if (j - arr[i] >= 0){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i]] + arr[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][s];
}
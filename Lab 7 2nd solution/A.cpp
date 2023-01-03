#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> ans;
    vector<int> arr;
    vector<int> dp;
    vector<int> prev;
    int data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        arr.push_back(data);
        dp.push_back(1);
        prev.push_back(-1);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
    int max = 0;
    int pos = 0;
    for (int i = 0; i < n; i++){
        if (dp[i] > max){
            max = dp[i];
            pos = i;
        }
    }
    while (pos != -1){
        ans.push_back(arr[pos]);
        pos = prev[pos];
    }
    reverse(ans.begin(), ans.end());
    cout << max << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
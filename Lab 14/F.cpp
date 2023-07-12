#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int *arr = new int[n];
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--){
        cin >> arr[i];
    }
    int start = n / 2;
    if (n % 2 == 1) start++;
    for (int i = start; i < n; i++){
        bool check = true;
        int jump = 1;
        for (int j = i; j < n; j++){
            if (arr[j] != arr[j - jump]){
                check = false;
                break;
            }
            jump += 2;
        }
        if (check) ans.push_back(i);
    }
    ans.push_back(n);
    for (auto i : ans) cout << i << " ";
}
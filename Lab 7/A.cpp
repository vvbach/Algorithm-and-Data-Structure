#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> ans;
    int a[2000];
    int prev[2000];
    int d[2000];
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++){
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++){
            if (a[i] > a[j] && d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }
    int length = 0;
    int pos = 0;
    for (int i = 0; i < n; i++){
        if (d[i] > length){
            length = d[i];
            pos = i;
        }
    }
    while (pos != -1){
        ans.push_back(a[pos]);
        pos = prev[pos];
    }
    cout << length << endl;
    for (int i = length - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
}
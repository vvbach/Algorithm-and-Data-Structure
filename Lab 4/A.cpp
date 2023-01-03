#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int a[100001];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    bool ans = true;
    for (int i = 1; i <= n / 2; i++){
        if (a[i] > a[2*i]){
            ans = false;
            break;
        }
        if (2*i + 1 <= n && a[i] > a[2*i]){
            ans = false;
            break;
        }
    }
    cout << (ans ? "YES" : "NO");
}
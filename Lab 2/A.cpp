#include <iostream>
using namespace std;

int main(){
    int a[1001];
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int num; cin >> num;
    int pos; cin >> pos;
    for (int i = n - 1; i >= pos - 1; i--){
        a[i + 1] = a[i];
    }
    a[pos - 1] = num;
    for (int i = 0; i < n + 1; i++){
        cout << a[i] << " ";
    }
    return 0;
}
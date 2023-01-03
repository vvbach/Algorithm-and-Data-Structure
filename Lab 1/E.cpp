#include <iostream>

using namespace std;


int main(){
    int n; cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x; cin >> x;
    int ans = 0;
    int min = 10000;
    for (int i = 0; i < n; i++)
    {
        if(abs(x - a[i]) < min){
            min = abs(x - a[i]);
            ans = a[i];
        }
    }
    cout << ans;
}
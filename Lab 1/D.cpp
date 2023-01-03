#include <iostream>

using namespace std;


int main(){
    int n; cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] < a[i] && a[i + 1] < a[i]){
            count++;
        }
    }
    cout << count;
}
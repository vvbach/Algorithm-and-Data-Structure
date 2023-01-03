#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    int n; cin >> n;
    int a[70000];
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int i = 2; i < n; i++) swap(a[i], a[i/2]);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
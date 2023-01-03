#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n; cin >> n;
    int a[35];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = n - 2; i >= 0; i--){
        swap(a[i], a[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}
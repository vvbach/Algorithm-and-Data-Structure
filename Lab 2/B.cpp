#include <iostream>
using namespace std;

int main(){
    int a[1000];
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int key;
    for (int i = 1; i < n; i++){
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
#include <iostream>
using namespace std;

void insertionSort(int a[], int n){
    int key;
    for (int i = 1; i < n; i++){
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main(){
    int a[1600];
    int n, m; 
    cin >> n >> m;
    for (int i = 0; i < n*m; i++){
        cin >> a[i];
    }
    int k; cin >> k;
    int b[2000];
    for (int i = 0; i < k; i++){
        cin >> b[i];
    }
    insertionSort(a, n*m);
    insertionSort(b, k);
    int j = 0;
    int count = 0;
    for (int i = 0; i < k; i++){
        if (b[i] <= a[j]){
            count++;
            j++;
        }
        if (j >= n * m){
            break;
        }
    }

    cout << count;
}
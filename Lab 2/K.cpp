#include <iostream>

using namespace std;

int ans;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void quickSort(int arr[], int l, int r, int k){
    if (l < r){
        int key = arr[(l + r) / 2];
        int i = l;
        int j = r;
        while(i <= j){
            while (arr[i] < key) i++;
            while (arr[j] > key) j--;
            if (i <= j){
                swap(arr[i++], arr[j--]);
            } 
        }
        
        if (l <= k && k <= j) quickSort(arr, l, j, k);
        else if (r >= k && k >= i) quickSort(arr, i, r, k);
        else {
            ans = arr[k];
        }
    }
    else {
        ans = arr[k];
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int a, b, c, a1, a2;
    cin >> a >> b >> c >> a1 >> a2;
    int *arr = new int[30000000];
    arr[0] = a1;
    arr[1] = a2;
    for (int i = 2; i < n; i++){
        arr[i] = a * arr[i - 2] + b * arr[i - 1] + c;
    }
    quickSort(arr, 0, n - 1, k - 1);
    cout << ans;
    return 0;
}
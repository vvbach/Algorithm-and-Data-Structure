#include <iostream>

using namespace std;

int BinarySearchLeft(int a[], int n, int x){
    int l = -1;
    int r = n;
    while (l + 1 < r){
        int mid = (l + r) / 2;
        if (a[mid] < x){
            l = mid;
        }
        else {
            r = mid;
        }
    }
    if (r < n && a[r] == x){
        return r + 1;
    }
    return -1;
}

int BinarySearchRight(int a[], int n, int x){
    int l = -1;
    int r = n;
    while (l + 1 < r){
        int mid = (l + r) / 2;
        if (a[mid] <= x){
            l = mid;
        }
        else {
            r = mid;
        }
    }
    if (l < n && a[l] == x){
        return l + 1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[100000];
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m; cin >> m;
    int x;
    for (int i = 0; i < m; i++){
        cin >> x;
        int l = BinarySearchLeft(a, n, x);
        int r = BinarySearchRight(a, n, x);
        cout << l << " " << r << endl;
    }
}
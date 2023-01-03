#include <iostream>
#include <iomanip>
using namespace std;

int check(double a1, double arr[], int n){
    arr[1] = a1;
    for (int i = 2; i < n; i++){
        arr[i] = 2 * arr[i - 1] + 2- arr[i - 2];
        if (arr[i] <= 0){
            return 0;
        }
    }
    return 1;
}

void BinarySearch(double l, double r, double arr[], int n){
    while (l < r){
        double mid = (l + r) / 2;
        if(l == mid | r == mid) break;
        if (check(mid, arr, n)){
            r = mid;
        }
        else {
            l = mid;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    double arr[1000];
    double a; cin >> a; 
    arr[0] = a;
    BinarySearch(0, a, arr, n);
    cout << setprecision(2) << fixed << arr[n - 1];
}
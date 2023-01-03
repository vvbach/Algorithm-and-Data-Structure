#include <iostream>
using namespace std;

int check(long long int value, long long int a[], int n, int k){
    int place = 0;
    int l = 0;
    int r;
    int count = 1;
    while(a[n] - a[place] > value){
        r = n;
        while (l + 1 < r){
            int mid = (l + r) / 2;
            if (a[mid] - a[place] <= value){
                l = mid;
            }
            else {
                r = mid;
            }
        }
        place = l;
        count++;
    }
    
    return (count <= k);

}

long long int BinarySearch(int l, long long int r, long long int a[], int n, int k){
    long long int mid;
    while (l < r){
        mid = (l + r) / 2;
        if (check(mid, a, n, k)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

void Divide(long long int value, long long int a[], int n, int k){
    int division[200001], final_div[200001];
    division[0] = 0; int index_division = 1;
    int place = 0;
    int l = 0;
    int r;
    int equal;
    while(a[n] - a[place] > value){
        r = n + 1;
        while (l + 1 < r){
            int mid = (l + r) / 2;
            if (a[mid] - a[place] <= value){
                l = mid;
                if (a[mid] - a[place] == value){
                    equal = mid;
                }
            }
            else {
                r = mid;
            }
        }
        place = l;
        division[index_division] = place; 
        index_division++;
        k--;
    }
    division[index_division] = n;
    index_division++;
    
    int i = 1;
    int index_final_div = 0;
    while (k > 1 && i < index_division){
        if (division[i] != equal && division[i] - division[i - 1] > 1){
            division[i - 1]++;
            final_div[index_final_div] = division[i - 1];
            index_final_div++;
            k--;
        }
        else {
            if (i < index_division - 1) {
                final_div[index_final_div] = division[i];
                index_final_div++;
            }
            i++;
        }
    }
    while (i < index_division - 1){
        final_div[index_final_div] = division[i];
        index_final_div++;
        i++;
    }
    
    for (int j = 0; j < index_final_div; j++) cout << final_div[j] << " ";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    long long int a[200001];
    long long int r = 0;
    long long int l = 0;
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
        a[i] += a[i - 1]; 
    }
    long long int s = BinarySearch(l, r, a, n, k);
    Divide(s, a, n, k);
    return 0;
}
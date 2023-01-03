#include <iostream>

using namespace std;

#define MAX 2000000000

int main(){
    int n; cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int min1 = MAX; 
    int index_min_1 = 0;
    int min2 = MAX;

    for (int i = 0; i < n; i++){
        if (a[i] < min1){
            min1 = a[i]; 
            index_min_1 = i;
        } 
    }
    for (int i = 0; i < n; i++){
        if (a[i] < min2 && i != index_min_1) min2 = a[i]; 
    }
    cout << min1 << " " << min2;
}
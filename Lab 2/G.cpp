#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right){
    int *mergeArr = new int[right - left + 1]; 
    int i1 = 0;
    int i2 = 0;
    while (left + i1 <= mid && mid + 1 + i2 <= right){
        if (arr[left + i1] < arr[mid + 1 + i2]){
            mergeArr[i1 + i2] = arr[left + i1];
            i1++;
        }
        else {
            mergeArr[i1 + i2] = arr[mid + 1 + i2];
            i2++;
        }
    }
    while (left + i1 <= mid){
        mergeArr[i1 + i2] = arr[left + i1];
        i1++;
    }
    while (mid + 1 + i2 <= right){
        mergeArr[i1 + i2] = arr[mid + 1 + i2];
        i2++;
    }
    for (int i = 0; i < right - left + 1; i++){
        arr[left + i] = mergeArr[i];
    }
    delete[] mergeArr;
}

void mergeSort(int arr[], int left, int right){
    if (left >= right){
        return;
    }
    int mid = (right + left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int simplifyArray(int a[], int a_sub[], int n){
    int j = 1;
    a_sub[0] = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] != a_sub[j - 1]){
            a_sub[j] = a[i];
            j++;
        }
    }
    return j;
}

int main(){
    int a[100000];
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b[100000];
    int m; cin >> m;
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    mergeSort(a, 0, n - 1);
    mergeSort(b, 0, m - 1);


    bool check = true;
    int a_sub[100000];
    int b_sub[100000];
    int n_sub = simplifyArray(a, a_sub, n);
    int m_sub = simplifyArray(b, b_sub, m);
    if (n_sub != m_sub){
        check = false;
    }
    else {
        for (int i = 0; i < n_sub; i++){
            if (a_sub[i] != b_sub[i]){
                check = false;
                break;
            }
        }
    }
    cout << (check ? "YES" : "NO");   
    
    return 0;
}
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

int main(){
    int a[100000];
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
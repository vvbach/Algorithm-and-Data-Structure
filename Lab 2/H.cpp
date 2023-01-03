#include <iostream>

using namespace std;

struct Segment{
    int begin;
    int end;
};



void merge(Segment arr[], int left, int mid, int right){
    Segment *mergeArr = new Segment[right - left + 1]; 
    int i1 = 0;
    int i2 = 0;
    while (left + i1 <= mid && mid + 1 + i2 <= right){
        if (arr[left + i1].begin < arr[mid + 1 + i2].begin){
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

void mergeSort(Segment arr[], int left, int right){
    if (left >= right){
        return;
    }
    int mid = (right + left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main(){
    Segment s[100000];
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i].begin >> s[i].end;
    }
    mergeSort(s, 0, n - 1);

    int count = 0;
    int start = s[0].begin;
    int finish = s[0].end;
    for (int i = 1; i < n; i++){
        if (s[i].begin > finish){
            count += finish - start + 1;
            start = s[i].begin;
            finish = s[i].end;
        }
        else {
            finish = max(finish, s[i].end);
        }
    }
    count += finish - start + 1;
    cout << count;
    return 0;
}
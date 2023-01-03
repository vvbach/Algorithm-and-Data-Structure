#include <iostream>
using namespace std;

int main(){
    int a[1000], b[1000];
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int id_key, score_key;
    for (int i = 1; i < n; i++){
        id_key = a[i];
        score_key = b[i];
        int j = i - 1;
        while (j >= 0 && (b[j] < score_key || (b[j] == score_key && a[j] > id_key))){
            a[j + 1] = a[j];
            b[j + 1] = b[j];
            j--;
        }
        a[j + 1] = id_key;
        b[j + 1] = score_key;
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}
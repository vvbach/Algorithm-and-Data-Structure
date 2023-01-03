#include <iostream>
#include <string.h>

using namespace std;

int tree[4 * 5 * 100000 + 1];
int cat[5 * 100000 + 1];

void update(int id, int l, int r, int i, int value){
    if (i < l || i > r){
        return;
    }
    if (cat[i] < 0){
        value = value - cat[i];
        cat[i] = 0;
    }
    tree[id] += value;
    if (l != r){
        int mid = (l + r) / 2;
        update(id * 2, l, mid, i, value);
        update(id * 2 + 1, mid + 1, r, i, value);
    }
}

int getSum(int id, int l, int r, int left, int right){
    if (right < l || r < left){
        return 0;
    }
    if (l >= left && r <= right){
        return tree[id];
    }
    int mid = (l + r) / 2;
    return getSum(2 * id, l, mid , left, right) + getSum(2 * id + 1, mid + 1, r, left, right);
}

int main(){
    int n, q;
    cin >> n >> q;
    memset(tree, 0, n * 4 + 1);
    memset(cat, 0, n + 1);
    char cmd;
    int data1, data2;
    for (int i = 0; i < q; i++){
        cin >> cmd >> data1 >> data2;
        if (cmd == '+'){
            cat[data1] += data2;
            update(1, 1, n, data1, data2);
        }
        else if (cmd == '-'){
            cat[data1] -= data2;
            update(1, 1, n, data1, -data2);
        } else {
            cout << getSum(1, 1, n, data1, data2) << endl;
        }
    }
}
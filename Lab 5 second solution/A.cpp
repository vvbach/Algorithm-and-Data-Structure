#include <iostream>
using namespace std;

int ans(int tree[][2], int n){
    if (n == 0) return 0;
    int l = ans(tree, tree[n - 1][0]);
    int r = ans(tree, tree[n - 1][1]);
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

int main(){
    int n; cin >> n;
    int tree[200000][2];
    int a, b, c;
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        tree[i][0] = b;
        tree[i][1] = c;
    }
    if (n == 0) cout << 0;
    else{
        cout << ans(tree, 1);
    }
    return 0;
}
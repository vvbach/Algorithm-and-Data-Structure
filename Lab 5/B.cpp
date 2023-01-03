#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
bool checkTree = true;
void check(int min, int max, int n){
    if (n == 0) return;
    
    if (tree[n - 1][0] <= min || tree[n - 1][0] >= max){
        checkTree = false;
    }
    check(min, tree[n - 1][0], tree[n - 1][1]);
    check(tree[n - 1][0], max, tree[n - 1][2]);
}

int main(){
    int n; cin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        tree.push_back({a, b, c});
    }
    if (n == 0){
        cout << "YES";
    }
    else {  
        check(-2000000000, 2000000000, 1);
        cout << (checkTree ? "YES" : "NO");
    }
    return 0;
}
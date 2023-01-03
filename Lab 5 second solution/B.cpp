#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
bool isTree = true;
void ans(int n, int min, int max){
    if (n == 0) return;
    
    if (tree[n - 1][0] <= min || tree[n - 1][0] >= max){
        isTree = false;
    }
    ans(tree[n - 1][1], min, tree[n - 1][0]);
    ans(tree[n - 1][2], tree[n - 1][0], max);
}

int main(){
    int n; cin >> n;
    int data, left, right;
    for (int i = 0; i < n; i++){
        cin >> data >> left >> right;
        tree.push_back({data, left, right});
    }
    if (n == 0) cout << "YES";
    else{
        ans(1, -2000000000, 2000000000);
        if (isTree) cout << "YES";
        else cout << "NO";
    }
    return 0;
}
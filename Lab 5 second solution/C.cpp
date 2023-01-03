#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
int num = 1;

void inorderTraversal(int n){
    if (n != 0){
        inorderTraversal(tree[n][1]);
        tree[n][0] = num;
        num++;
        inorderTraversal(tree[n][2]);
    }
}

int main(){
    int n; cin >> n;
    tree.push_back({0, 0 ,0});
    int left, right;
    for (int i = 0; i < n; i++){
        cin >> left >> right;
        tree.push_back({0, left, right});
    }
    inorderTraversal(1);
    for (int i = 1; i <= n; i++){
        cout << tree[i][0] << " ";
    }
    return 0;
}
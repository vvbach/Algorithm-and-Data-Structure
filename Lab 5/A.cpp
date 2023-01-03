#include <iostream>
using namespace std;

struct Node {
    int value;
    int left;
    int right;
};

int getHeight(Node tree[], int n){
    if (n == 0) return 0;
    int lMax = getHeight(tree, tree[n - 1].left);
    int rMax = getHeight(tree, tree[n - 1].right);
    return (lMax > rMax) ? (lMax + 1) : (rMax + 1);
}

int main(){
    int n; cin >> n;
    Node *tree = new Node[n];
    int a, b, c;
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        tree[i].value = a;
        tree[i].left = b;
        tree[i].right = c;
    }
    if (n == 0){
        cout << 0;
    }
    else {  
        cout << getHeight(tree, 1);
    }
    return 0;
}
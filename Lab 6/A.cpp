#include <iostream>
using namespace std;

struct Node {
    int value;
    int left;
    int right;
    int height;
};

int getHeight(Node tree[], int n){
    if (n == 0) {
        return 0;
    }
    int lMax = getHeight(tree, tree[n].left);
    int rMax = getHeight(tree, tree[n].right);
    tree[n].height = (lMax > rMax) ? (lMax + 1) : (rMax + 1);
    return (lMax > rMax) ? (lMax + 1) : (rMax + 1);
}

int main(){
    int n; cin >> n;
    Node *tree = new Node[n + 1];
    int a, b, c;
    for (int i = 1; i <= n; i++){
        cin >> a >> b >> c;
        tree[i].value = a;
        tree[i].left = b;
        tree[i].right = c;
    }
    tree[0].height = 0;
    getHeight(tree, 1);
    
    for (int i = 1; i <= n; i++){
        cout << tree[tree[i].right].height - tree[tree[i].left].height << endl;
    }
    return 0;
}
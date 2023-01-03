#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    int left;
    int right;
};
vector<Node> tree;
int value = 1;

void insertMin(int i){
    if (i != 0){
        insertMin(tree[i].left);
        tree[i].value = value;
        value++;
        insertMin(tree[i].right);
    }
}

int main(){
    int n; cin >> n;
    tree.push_back({0, 0 ,0});
    for (int i = 1; i <= n; i++){
        Node node;
        cin >> node.left >> node.right;
        node.value = 0;
        tree.push_back(node);
    }
    insertMin(1);
    for (int i = 1; i <= n; i++){
        cout << tree[i].value << " ";
    }
    return 0;
}
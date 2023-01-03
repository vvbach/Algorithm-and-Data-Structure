#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
};


Node* createNode(int key){
    Node* n = new Node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}


Node* buildTree(int min, int max, int arr[], int& index, int n){
    if (index >= n) return nullptr;
    int key = arr[index];
    Node* node = nullptr;
    if (arr[index] > min && arr[index] < max){
        node = createNode(key);
        index++;
        if (index < n){
            node->left = buildTree(min, key, arr, index, n);
        }
        if (index < n){
            node->right = buildTree(key, max, arr, index, n);
        }
    }
    return node;  
}

void printAns(Node* node){
    if (node == nullptr){
        return;
    }
    printAns(node->left);
    printAns(node->right);
    cout << node->key << " ";
}


int main(){
    int n; cin >> n;
    int array[200000];
    int index = 0;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    Node* tree = nullptr;
    tree = buildTree(-2000000000, 2000000000, array, index, n);
    printAns(tree);
}
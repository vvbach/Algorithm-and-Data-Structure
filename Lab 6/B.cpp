#include <iostream>

using namespace std;

struct Node {
    int index;
    int data;
    Node* left;
    Node* right;
};

int tree[200001][3];
int in = 1;

Node* buildTree(int i){
    if (i == 0) return nullptr;
    Node* node = new Node;
    node->data = tree[i][0];
    node->left = buildTree(tree[i][1]);
    node->right = buildTree(tree[i][2]);
    return node;
}

Node* smallRotate(Node* root){
    Node *p = root->right;
    root->right = p->left;
    p->left = root;
    return p;
}

Node* bigRotate(Node* root){
    Node *p = root->right;
    Node* q = p->left;
    root->right = q->left;
    p->left = q->right;
    q->left = root;
    q->right = p;
    return q;
}

int getHeight(Node* root){
    if (root == nullptr) return 0;
    int lMax = getHeight(root->left);
    int rMax = getHeight(root->right);
    return (lMax > rMax) ? (lMax + 1) : (rMax + 1);
}

int getBalance(Node* root){
    return getHeight(root->right) - getHeight(root->left); 
}


void indexing(Node* root){
    if (root != nullptr){
        root->index = in++;
        indexing(root->left);
        indexing(root->right); 
    }
}

void printAns(Node* node){
    if (node == nullptr){
        return;
    }
    cout << node->data << " " << (node->left ? node->left->index : 0) << " " << (node->right ? node->right->index : 0) << endl;
    printAns(node->left);
    printAns(node->right);
}


int main(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
    }
    Node* root = buildTree(1);
    if (getBalance(root->right) == -1){
        root = bigRotate(root);
    } else {
        root = smallRotate(root);
    }
    indexing(root);
    cout << n << endl;
    printAns(root);
}
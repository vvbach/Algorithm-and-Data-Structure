#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
};

Node* createNode(int x){
    Node *n = new Node;
    n->data = x;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void fixHeight(Node* root){
    int r = (root->right == nullptr) ? 0 : root->right->height;
    int l = (root->left == nullptr) ? 0 : root->left->height;
    root->height = max(l, r) + 1;
}

Node* LeftRotate(Node* root){
    Node *p = root->right;
    root->right = p->left;
    p->left = root;
    fixHeight(root);
    fixHeight(p);
    return p;
}

Node* RightRotate(Node* root){
    Node *p = root->left;
    root->left = p->right;
    p->right = root;
    fixHeight(root);
    fixHeight(p);
    return p;
}

int getBalance(Node* root){
    if (root == nullptr) return 0;
    int r = (root->right == nullptr) ? 0 : root->right->height;
    int l = (root->left == nullptr) ? 0 : root->left->height;
    return r - l;
}

Node* balance(Node* root){
    fixHeight(root);
    if (getBalance(root) == -2){
        if (getBalance(root->left) > 0){
            root->left = LeftRotate(root->left);
        }
        return RightRotate(root);
    }
    else if (getBalance(root) == 2){
        if (getBalance(root->right) < 0){
            root->right = RightRotate(root->right);
        }
        return LeftRotate(root);
    }
    return root;
}

Node* insert(Node* root, int x){
    if (root == nullptr) root = createNode(x);
    else if (x < root->data){
        root->left =  insert(root->left, x);
    } else if (x > root->data){
        root->right = insert(root->right, x);
    }
    return balance(root);
}

Node *maximum(Node *node){
    if (node->right == NULL){
        return node;
    }
    return maximum(node->right);
}
Node* Delete(Node *node, int x) {
    if (node == NULL){
        return node;
    }
    if (x < node->data) {
        node->left = Delete(node->left, x);
    }
    else if (x > node->data) {
        node->right = Delete(node->right, x);
    }
    else if ((node->left != NULL) && (node->right != NULL)){
        node->data = maximum(node->left)->data;
        node->left = Delete(node->left, node->data);
    }
    else {
        if (node->left != NULL) {
            node = node->left;
        }
        else if (node->right != NULL) {
            node = node->right;
        }
        else {
            node = NULL;
        }
    }
    if (node == NULL) {
        return node;
    }
    return balance(node);
};

Node* Search(Node* node, int value){
    if (node == nullptr) return nullptr;
    if (node->data == value) return node;
    if (node->data > value){
        return Search(node->left, value);
    } else if (node->data < value){
        return Search(node->right, value);
    } 
}

int main(){
    int n; cin >> n;
    char cmd;
    int data;
    Node* root = nullptr;
    for (int i = 0; i < n; i++){
        cin >> cmd >> data;
        if (cmd == 'A'){
            root = insert(root, data);
            cout << getBalance(root) << endl;
        }
        else if (cmd == 'D'){
            root = Delete(root, data);
            cout << getBalance(root) << endl;
        }
        else {
            if (Search(root, data) != nullptr){
                cout << "Y" << endl;
            }
            else cout << "N" << endl;
        }
    }
}
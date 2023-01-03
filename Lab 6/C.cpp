#include <iostream>

using namespace std;

struct Node {
    int index;
    int data;
    int height;
    Node* left;
    Node* right;
};

int tree[200001][3];
int in = 1;

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

int getHeight(Node* root){
    if (root == nullptr) return 0;
    int lMax = getHeight(root->left);
    int rMax = getHeight(root->right);
    root->height = (lMax > rMax) ? (lMax + 1) : (rMax + 1);
    return (lMax > rMax) ? (lMax + 1) : (rMax + 1);
}

int getBalance(Node* root){
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

Node* buildTree(int i){
    if (i == 0) return nullptr;
    Node* node = new Node;
    node->data = tree[i][0];
    node->left = buildTree(tree[i][1]);
    node->right = buildTree(tree[i][2]);
    return node;
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
    int x; cin >> x;
    Node* root;
    if (n == 0){
        root = createNode(x);
    }else {

        root = buildTree(1);
    }
    getHeight(root);
    root = insert(root, x);
    indexing(root);
    cout << n + 1 << endl;
    printAns(root);
}
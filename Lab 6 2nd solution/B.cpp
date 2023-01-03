
#include <iostream>

using namespace std;

struct Node
{
    int data;
    int index;
    Node *left;
    Node *right;
    int height;
};

int number = 1;

Node* build(int tree[][3], int i){
    if (i == 0) return nullptr;
    Node* root = new Node;
    root->data = tree[i][0];
    root->left = build(tree, tree[i][1]);
    root->right = build(tree, tree[i][2]);
    return root;
}

int getHeight(Node* root){
    if (root == nullptr) return 0;
    int lMax = getHeight(root->left);
    int rMax = getHeight(root->right);
    root->height = (lMax > rMax) ? (lMax + 1) : (rMax + 1);
    return (lMax > rMax) ? (lMax + 1) : (rMax + 1);
}

int balance(Node* root){
    return root->right->height - root->left->height; 
}

Node *rightRotate(Node *root)
{
    Node *x = root->left;

    root->left = x->right;
    x->right = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node *leftRotate(Node *root)
{
    Node *y = root->right;

    root->right = y->left;
    y->left = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

void numbering(Node* root){
    if (root != nullptr){
        root->index = number;
        number++;
        numbering(root->left);
        numbering(root->right); 
    }
}

void printAns(Node* root){
    if (root == nullptr){
        return;
    }
    cout << root->data << " " << (root->left ? root->left->index : 0) << " " << (root->right ? root->right->index : 0) << endl;
    printAns(root->left);
    printAns(root->right);
}

int main()
{
    int n; cin >> n;
    int tree[300000][3];
    for (int i = 1; i <= n; i++){
        cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
    }
    Node* root = build(tree, 1);
    getHeight(root);
    if (balance(root->right) == -1){
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    } else {
        root = leftRotate(root);
    }
    numbering(root);
    cout << n << endl;
    printAns(root);
    
}
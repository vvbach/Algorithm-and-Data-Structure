
#include <iostream>
#include <cmath>
#define COUNT 10

using namespace std;

struct Node
{
    int index;
    int data;
    Node *left;
    Node *right;
    int height;
};

int tree[200001][3];
int number = 1;
Node *build(int tree[][3], int i)
{
    if (i == 0)
        return nullptr;
    Node *root = new Node;
    root->data = tree[i][0];
    root->left = build(tree, tree[i][1]);
    root->right = build(tree, tree[i][2]);
    return root;
}

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;
    // return 1 + max(getHeight(root->left), getHeight(root->right));
    return root->height;
}

Node *rightRotate(Node *root)
{
    Node *x = root->left;

    // Bắt đầu quay phải
    root->left = x->right;
    x->right = root;

    // Thiết lập chiều cao
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    // Return x - trả về root mới
    return x;
}

Node *leftRotate(Node *root)
{
    Node *y = root->right;

    // Bắt đầu quay trái
    root->right = y->left;
    y->left = root;

    // Thiết lập chiều cao
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    // Return y - trả về root mới
    return y;
}
// Insertion - AVL Tree
Node *Insert(Node *root, int value)
{
    // 1. Insert
    if (root == NULL)
        return new Node{0, value, NULL, NULL, 1}; // Trả về Node có height = 1
    if (value > root->data)
        root->right = Insert(root->right, value);
    else if (value < root->data)
        root->left = Insert(root->left, value);
    else
        return root; // Neu bang thi khong them

    // 2. Set height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Rotate
    int valBalance = getHeight(root->left) - getHeight(root->right);

    // Kiểm tra 4 TH xảy ra:
    // 3.1. Left left
    if (valBalance > 1 && value < root->left->data)
        return rightRotate(root);

    // 3.2. Right Right
    if (valBalance < -1 && value > root->right->data)
        return leftRotate(root);

    // 3.3. Left Right
    if (valBalance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 3.4. Right Left
    if (valBalance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void numbering(Node *root)
{
    if (root != nullptr)
    {
        root->index = number;
        number++;
        numbering(root->left);
        numbering(root->right);
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

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
    }
    int x;
    cin >> x;
    Node *root;
    if (n == 0){
        root = Insert(root, x);
    }else {

        root = build(tree, 1);
    }

    getHeight(root);
    root = Insert(root, x);
    numbering(root);
    cout << n + 1 << endl;
    printAns(root);
}
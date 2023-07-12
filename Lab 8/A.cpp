#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int data;
    int index;
    Node* left;
    Node* right;
    Node* parent;
    Node(int data, int index){
        this->index = index;
        this->left = nullptr;
        this->right = nullptr; 
        this->data = data;
        this->parent = nullptr;
    }
};

Node* build(Node* root, vector<Node*>& vector_node, int n){
    root = vector_node[0];
    for (int i = 0; i < n; i++){
        if (2 * i + 1 < n){
            vector_node[i]->left = vector_node[2 * i + 1];
            vector_node[2 * i + 1]->parent = vector_node[i];
        }
        if (2 * i + 2 < n){
            vector_node[i]->right = vector_node[2 * i + 2];
            vector_node[2 * i + 2]->parent = vector_node[i];
        }
    }
    return root;
}

Node* change(Node* root, int index, vector<Node*>& vector_node){
    Node* v = vector_node[index];
    Node* p = v->parent;
    if (v == root) return root;
    Node* pp = p->parent;
    if (v == p->left){
        p->left = v->left;
        if (v->left != nullptr) v->left->parent = p;
        v->left = p;
        p->parent = v;
        if (root == p){ //This is root
            root = v;
        }
        else {
            if (p == pp->left){
                pp->left = v;
                v->parent = pp;
            }
            else {
                pp->right = v;
                v->parent = pp;
            }
        }
    } else {
        p->right = v->right;
        if (v->right != nullptr) v->right->parent = p;
        v->right = p;
        p->parent = v;
        if (root == p){ //This is root
            root = v;
        }
        else {
            if (p == pp->left){
                pp->left = v;
                v->parent = pp;
            }
            else {
                pp->right = v;
                v->parent = pp;
            }
        } 
    }
    return root;
}

void LRV(vector<int> &RLE, Node* root){
    if (root == nullptr) return;
    LRV(RLE, root->left);
    LRV(RLE, root->right);
    RLE.push_back(root->data);
}



int main(){
    int n, q1, q2;
    int x;
    Node *tree_num = nullptr;
    Node *tree_char = nullptr;
    vector<Node*> node_num, node_char;
    vector<int> RLE_num, RLE_char;

    cin >> n >> q1;
    for (int i = 0; i < n; i++){
        cin >> x;
        node_num.push_back(new Node(x, i));
    } 
    tree_num = build(tree_num, node_num, n);
    for (int i = 0; i < q1; i++){
        cin >> x;
        tree_num = change(tree_num, x - 1, node_num);
    }
    LRV(RLE_num, tree_num);

    cin >> n >> q2;
    char c;
    for (int i = 0; i < n; i++){
        cin >> c;
        x = c;
        node_char.push_back(new Node(x, i));
    } 
    tree_char = build(tree_char, node_char, n);

    for (int i = 0; i < q2; i++){
        cin >> x;
        tree_char = change(tree_char, x - 1, node_char);
    }
    LRV(RLE_char, tree_char);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < RLE_num[i]; j++){
            cout << (char)RLE_char[i];
        }
    }
    return 0;
}
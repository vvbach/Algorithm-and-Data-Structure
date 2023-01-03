#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
 
 
struct Node {
    int data;
    int height;
    int idx;
    Node *left;
    Node *right;
 
    Node(){}
    Node(const int& data_, const int& idx_=0, const int& height_=1,  Node *l = nullptr, Node *r = nullptr) :
        data(data_), idx(idx_), height(height_), left(l), right(r) {}
 
};
 
class AVL {
private:
    Node *root;
 
    int countHeight(Node *node) {
        int left_height = 0;
        int right_height = 0;
        if (node->left) {
            left_height = countHeight(node->left);
        }
        if (node->right) {
            right_height = countHeight(node->right);
        }
        node->height = max(left_height, right_height) + 1;
        return max(left_height, right_height) + 1;
    }
    int getBalance(Node *node) {
        if (node->left && node->right) 
            return node->right->height - node->left->height;
        if (node->left) 
            return -1 * node->left->height;
        if (node->right)
            return node->right->height;
        return 0;
    }
    void fixheight(Node *node) {
        int l = node->left == nullptr ? 0 : node->left->height;
        int r = node->right == nullptr ? 0 : node->right->height;
        node->height = max(l, r) + 1;
    }
    Node *rotateRight (Node *node){
        Node *new_node = node->left;
        node->left = new_node->right;
        new_node->right = node;
        fixheight(node);
        fixheight(new_node);
        return new_node;
    }
 
    Node * rotateLeft(Node *new_node){
        Node * node = new_node->right;
        new_node->right = node->left;
        node->left = new_node;
        fixheight(new_node);
        fixheight(node);
        return node;
    }
    Node *balance(Node *node) {
        fixheight(node);    
        if (getBalance(node) == 2) {
            if (getBalance(node->right) < 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        if (getBalance(node) == -2) {
            if (getBalance(node->left) > 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        return node;
    }
    Node *insert_(Node *node, int value) {
        if (!node) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert_(node->left, value);
        } else {
            node->right = insert_(node->right, value);
        }
        return balance(node);
    }
    Node *removeMin(Node *node) {
        if (!node) {
            return nullptr;
        }
        if (!node->right) {
            return node->left;
        }
        node->right = removeMin(node->right);
        return balance(node);
    }
    Node *find_max(Node *node){
        if (node->right == NULL){
            return node;
        }
        return find_max(node->right);
    }
    Node *remove_(Node *node, int value) {  
        if (node == NULL){
            return node;
        }
        if (value < node->data) {
            node->left = remove_(node->left, value);
        }
        else if (value > node->data) {
            node->right = remove_(node->right, value);
        }
        else if ((node->left != NULL) && (node->right != NULL)){
            node->data = find_max(node->left)->data;
            node->left = remove_(node->left, node->data);
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
    }
            
public:
 
    AVL() {
        root = nullptr;
    };

    void insert(int value) {
        
        root = insert_(root, value);
    }
    void remove(int value) {
        
        root = remove_(root, value);
    }
    char exists (const int& value) const{
        Node *new_root = root;
        while (new_root) { 
            if (value == new_root->data) {
                return 'Y';
            }

            if (value < new_root->data) {
                new_root = new_root->left;
            } else {
                new_root = new_root->right;
            }
        }
        return 'N';
    }
    int getBalanceRoot() {
        if (root == nullptr) {
            return 0;
        }
        Node *start = root;
        return getBalance(start);
    }
};
 

int main(){
    int n;
    int sivaluee = 0;
 
    cin >> n;
    
    AVL avl;
    
    for (int i = 0; i < n; i++) {
        int x;
        char type;
        cin >> type >> x;
        if (type == 'A') {
            avl.insert(x); 
            sivaluee++;
            if (sivaluee == 1) {
                cout << 0 << endl;
            } else {
                cout << avl.getBalanceRoot() << endl;
            }
        }
        if (type == 'D') {
            if (sivaluee > 0) {
                avl.remove(x);
                cout << avl.getBalanceRoot() << endl;
                sivaluee--;
            } else {
                cout << 0 << endl;
            }
        }
        if (type == 'C') {
            cout << avl.exists(x) << endl;
        }
    }
}
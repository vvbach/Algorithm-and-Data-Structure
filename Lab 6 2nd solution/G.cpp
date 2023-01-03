#include <tuple>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

 
struct Node {
    string data;
    int height;
    int idx;
    Node *left;
    Node *right;
 
    Node(){}
    Node(const string& data_, const int& idx_=0, const int& height_=1,  Node *l = nullptr, Node *r = nullptr) :
        data(data_), idx(idx_), height(height_), left(l), right(r) {}
 
};
 
class AVL {
private:
    Node *root;
    
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
    Node *insert_(Node *node, string value) {
        if (!node) {
            this->exist = false;
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert_(node->left, value);
        } else if (value > node->data){
            node->right = insert_(node->right, value);
        }
        return balance(node);
    }

public:
    bool exist;
    AVL() {
        root = nullptr;
    };

    void insert(string value) {
        root = insert_(root, value);
    }
};
 
int main() {
    int n; cin >> n;
    AVL avl;
    string s;
    int ans = 0;
    for (int j = 0; j < n; j++){
        cin >> s;
        avl.exist = true;
        avl.insert(s);
        if (avl.exist){
            int character[123] = {0};
            for (int i = 0; i < s.size(); i++){
                if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'a' && s[i] <= 'z')){
                    character[s[i]]++;
                }
            }
            for (int i = 48; i <= 122; i++){
                if (character[i] > 0) ans++;
            } 
        }
    }
    cout << ans;
    return 0;
}
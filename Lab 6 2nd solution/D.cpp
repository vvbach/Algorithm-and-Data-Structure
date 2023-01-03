#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
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
    Node *insert_(Node *node, string value) {
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

    Node *remove_(Node *node, string value) {  
        if (!node) {
            return nullptr;
        }
        if (node->data > value) {
            node->left = remove_(node->left, value);
        } else if (node->data < value) {
            node->right = remove_(node->right, value);
        } else {
            Node *l = node->left;
            Node *r = node->right;
            if (!l) {
                return r;
            }
            Node *a = l;
            while (a->right) {
                a = a->right;
            }
            a->left = removeMin(l);
            a->right = r;
            return balance(a);
        }
        return balance(node);
    }
            
public:
 
    AVL() {
        root = nullptr;
    };

    void insert(string value) {
        
        root = insert_(root, value);
    }
    void remove(string value) {
        
        root = remove_(root, value);
    }
    char exists (const string& value) const{
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
};
 
int main() {
 
    AVL student[3];
    int n; cin >> n;
    vector<vector<string>> s(3);
    string data;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            cin >> data;
            s[i].push_back(data);
            student[i].insert(data);
        }   
    } 
    int point[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            int c = 0;
            int st[3] = {0, 0, 0};
            for (int k = 0; k < 3; k++){
                if (student[k].exists(s[i][j]) == 'Y'){
                    c++;
                    st[k] = 1;
                    student[k].remove(s[i][j]);
                }
            }
            if (c == 1){
                for (int p = 0; p < 3; p++){
                    if (st[p] == 1) point[p] += 3;
                }
            }
            else if (c == 2) {
                for (int p = 0; p < 3; p++){
                    if (st[p] == 1) point[p] += 1;
                }
            }
        }
    }

    for(int i = 0; i < 3; i++){
        cout << point[i] << " ";
    }
	return 0;
}
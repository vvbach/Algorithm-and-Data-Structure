#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string data;
    int height;
    Node* left;
    Node* right;
};
bool found;
Node* createNode(string x){
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

Node* insert(Node* root, string x){
    if (root == nullptr) {
        root = createNode(x);
        found = false;
    }
    else if (x < root->data){
        root->left =  insert(root->left, x);
    } else if (x > root->data){
        root->right = insert(root->right, x);
    }
    return balance(root);
}

int ByteSaved(string s){
    int character[62] = {0}; //0-9 - number; 10 - 35 - a-z ; 36 - 61 - A-Z
    for (int i = 0; i < s.size(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            character[s[i] - '0']++;
        } else if (s[i] >= 'a' && s[i] <= 'z'){
            character[s[i] - 'a' + 10]++;
        } else if (s[i] >= 'A' && s[i] <= 'Z'){
            character[s[i] - 'A' + 36]++;
        }
    }
    int byte = 0;
    for (int i = 0; i < 62; i++){
        if (character[i] > 0) byte++;
    } 
    return byte;
}

int main(){
    int n; cin >> n;
    string s;
    Node* root = nullptr;
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> s;
        found = true;
        root = insert(root, s);
        if (found){
            ans += ByteSaved(s);
        }
    }
    cout << ans;
}
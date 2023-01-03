#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string data;
    int height;
    Node* left;
    Node* right;
};

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
    if (root == nullptr) root = createNode(x);
    else if (x < root->data){
        root->left =  insert(root->left, x);
    } else if (x > root->data){
        root->right = insert(root->right, x);
    }
    return balance(root);
}

Node* Delete(Node* node, string value){
    if (node == nullptr) return node;
    if (node->data > value){
        node->left = Delete(node->left, value);
    } else if (node->data < value){
        node->right = Delete(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr){
            Node* temp = node;
            node = nullptr;
            delete temp;
        }
        else if (node->left == nullptr || node->right == nullptr){
            if (node->left == nullptr){
                Node* temp = node;
                node = node->right;
                delete temp;
            } else {
                Node* temp = node;
                node = node->left;
                delete temp;
            }
        } else {
            Node *n = node->right;
            while (n->left != nullptr) {
                n = n->left;
            }
            node->data = n->data;
            node->right = Delete(node->right, n->data);
        }
    }
    if (node == nullptr) return node;
    return balance(node);
} 

Node* Search(Node* node, string value){
    if (node == nullptr) return nullptr;
    if (node->data == value) return node;
    if (node->data > value){
        return Search(node->left, value);
    } else if (node->data < value){
        return Search(node->right, value);
    } 
}

int main(){
    Node* s1 = nullptr;
    Node* s2 = nullptr;
    Node* s3 = nullptr;
    Node* student[3] = {s1, s2, s3};
    vector<vector<string>> task(3);
    int point[3] = {0, 0 ,0};
    string data;
    int n; cin >> n;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            cin >> data;
            task[i].push_back(data);
            student[i] = insert(student[i], data);
        }   
    } 
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            int count = 0;
            bool s_do[3] = {0, 0, 0};
            for (int k = 0; k < 3; k++){
                if (Search(student[k], task[i][j]) != nullptr){
                    count++;
                    s_do[k] = 1;
                    student[k] = Delete(student[k], task[i][j]);
                }
            }
            switch (count)
            {
            case 1:
                for (int p = 0; p < 3; p++){
                    point[p] += (s_do[p] ? 3 : 0);
                }
                break;
            case 2:
                for (int p = 0; p < 3; p++){
                    point[p] += (s_do[p] ? 1 : 0);
                }
                break;
            default:
                break;
            }
        }
    }

    for(int i = 0; i < 3; i++){
        cout << point[i] << " ";
    }
    return 0;
}
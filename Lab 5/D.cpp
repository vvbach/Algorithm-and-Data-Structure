#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(){
        this->left = nullptr;
        this->right = nullptr; 
    }
};

Node* insert(Node* node, int data){
    if (node == nullptr){
        node = new Node;
        node->data = data;
    } else if (data < node->data){
        node->left =  insert(node->left, data);
    } else if (data > node->data){
        node->right = insert(node->right, data);
    }
    return node;
}

Node* Search(Node* node, int value){
    if (node == nullptr) return nullptr;
    if (node->data == value) return node;
    if (node->data > value){
        return Search(node->left, value);
    } else if (node->data < value){
        return Search(node->right, value);
    } 
}

Node* prev(Node* node, int x){
    Node* current = node;
    Node* ans = nullptr;
    while(current != nullptr){
        if (current->data >= x){
            current = current->left;
        }
        else {
            ans = current;
            current = current->right;
        }
    }
    return ans;
}

Node* next(Node* node, int x){
    Node* current = node;
    Node* ans = nullptr;
    while(current != nullptr){
        if (current->data <= x){
            current = current->right;
        }
        else {
            ans = current;
            current = current->left;
        }
    }
    return ans;
}

Node* Delete(Node* node, int value){
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
            Node* p = node;
            Node *n = node->right;
            while (n->left != nullptr) {
                p = n;
                n = n->left;
            }
            node->data = n->data;
            if (p != node) p->left = n->right;
            else p->right = n->right;
            delete n;
        }
    }
    return node;
} 

int main(){
    Node* tree = nullptr;
    string command;
    int x;
    while(cin >> command){
        if (command == "insert"){
            cin >> x;
            tree = insert(tree, x);
        }
        if (command == "delete"){
            cin >> x;
            tree = Delete(tree, x);
        }
        if (command == "exists"){
            cin >> x;
            Node* ans = Search(tree, x);
            cout << ((ans != nullptr) ? "true" : "false") << endl;
        }
        if (command == "next"){
            cin >> x;
            Node* ans = next(tree, x);
            if (ans != nullptr) {
                cout << ans->data << endl;
            } else {
                cout << "none" << endl;
            }
        } 
        if (command == "prev"){
            cin >> x;
            Node* ans = prev(tree, x);
            if (ans != nullptr) {
                cout << ans->data << endl;
            } else {
                cout << "none" << endl;
            }
        } 
    }
    return 0;
}


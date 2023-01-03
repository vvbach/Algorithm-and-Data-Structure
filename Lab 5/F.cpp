#include <iostream>
#include <stack>

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

Node* createNode(int value){
    Node* n = new Node;
    n->data = value;
    return n;
}

void printAns(Node* node){
    if (node == nullptr){
        return;
    }
    printAns(node->left);
    printAns(node->right);
    cout << node->data << " ";
}

int main(){
    int n; cin >> n;
    Node* tree = nullptr;
    stack<Node*> st;
    int data;
    for (int i = 0; i < n; i++){
        cin >> data;
        if (i == 0){
            tree = createNode(data);
            st.push(tree);
        } else {
            Node* n = createNode(data);
            Node* prev = nullptr;
            while (!empty(st) && n->data > st.top()->data){
                prev = st.top();
                st.pop();
            }
            if (prev != nullptr){
                prev->right = n;
                st.push(n);
            } else {
                st.top()->left = n;
                st.push(n);
            }
        }

    }
    printAns(tree);
    return 0;
}
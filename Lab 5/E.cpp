#include <iostream>
#include <vector>

using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
    Node(){
        this->left = nullptr;
        this->right = nullptr; 
    }
};

Node* insert(Node* node, string data){
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

Node* Search(Node* node, string value){
    if (node == nullptr) return nullptr;
    if (node->data == value) return node;
    if (node->data > value){
        return Search(node->left, value);
    } else if (node->data < value){
        return Search(node->right, value);
    } 
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

void printAns(Node* node){
    if (node == nullptr){
        return;
    }
    
    cout << node->data << " ";
    printAns(node->left);
    printAns(node->right);
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
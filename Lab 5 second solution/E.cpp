#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
	string key;
	Node *parent;
	Node *left;
	Node *right;
};

Node* bstSearch(Node* &root, string item)
{
    Node *curNode = root;

    while (curNode != NULL && item != curNode->key)
    {
        if (item < curNode->key)
        {
            curNode = curNode->left;
        }
        else
        {
            curNode = curNode->right;
        }
    }

    return curNode;
}

bool bstExists(Node* &root, string item)
{
    return bstSearch(root, item) != NULL;
}

Node* bstNext(Node* &root, string item)
{
    Node *curNode = root;
    Node *sucNode = NULL;

    while (curNode != NULL)
    {
        if (curNode->key > item)
        {
            sucNode = curNode;
            curNode = curNode->left;
        }
        else
        {
            curNode = curNode->right;
        }
    }

    return sucNode;
}

Node* bstPrev(Node* &root, string item)
{
    Node *curNode = root;
    Node *prevNode = NULL;

    while (curNode != NULL)
    {
        if (curNode->key < item)
        {
            prevNode = curNode;
            curNode = curNode->right;
        }
        else
        {
            curNode = curNode->left;
        }
    }

    return prevNode;
}

void bstInsert(Node* &root, string item)
{
    if (bstExists(root, item))
    {
        return;
    }

    Node *newNode = new Node;

    newNode->key = item;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;

    Node *curPos = root;

    while (curPos != NULL)
    {
        newNode->parent = curPos;
        if (newNode->key < curPos->key)
        {
            curPos = curPos->left;
        }
        else
        {
            curPos = curPos->right;
        }
    }

    if (newNode->parent == NULL)
    {
        root = newNode;
    }
    else
    {
        if (newNode->key < newNode->parent->key)
        {
            newNode->parent->left = newNode;
        }
        else
        {
            newNode->parent->right = newNode;
        }
    }
}

void bstRemove(Node* &root, string item)
{
    Node *delNode = bstSearch(root, item);

    if (delNode == NULL)
    {
        return;
    }

    Node *pre;
    Node *u;

    if (delNode->left == NULL || delNode->right == NULL)
    {
        pre = delNode;
    }
    else
    {
        pre = bstNext(root, item);
    }

    if (pre->left != NULL)
    {
        u = pre->left;
    }
    else
    {
        u = pre->right;
    }

    if (u != NULL)
    {
        u->parent = pre->parent;
    }

    if (pre->parent == NULL)
    {
        root = u;
    }
    else
    {
        if (pre == pre->parent->left)
        {
            pre->parent->left = u;
        }
        else
        {
            pre->parent->right = u;
        }
    }

    if (pre != delNode)
    {
        delNode->key = pre->key;
    }

    delete pre;
}


int main()
{
    Node* student[3] = {nullptr, nullptr, nullptr};
    string s[3][10000];
    int n; cin >> n;
    string data;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            cin >> data;
            s[i][j] = data;
            bstInsert(student[i], data);
        }   
    } 
    int point[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            int c = 0;
            int st[3] = {0, 0, 0};
            for (int k = 0; k < 3; k++){
                if (bstSearch(student[k], s[i][j]) != nullptr){
                    c++;
                    st[k] = 1;
                    bstRemove(student[k], s[i][j]);
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

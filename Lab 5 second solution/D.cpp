#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
	int key;
	Node *parent;
	Node *left;
	Node *right;
};


Node *root = NULL;

Node* bstSearch(int item)
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

bool bstExists(int item)
{
    return bstSearch(item) != NULL;
}

Node* bstNext(int item)
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

Node* bstPrev(int item)
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

void bstInsert(int item)
{
    if (bstExists(item))
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

void bstRemove(int item)
{
    Node *delNode = bstSearch(item);

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
        pre = bstNext(item);
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
	string command;

	int value;

	while (cin >> command >> value)
	{
		if (command == "insert")
		{
			bstInsert(value);
		}

		if (command == "delete")
		{
			bstRemove(value);
		}

		if (command == "exists")
        {
            if (bstSearch(value))
            {
                cout << "true\n";
            }
			else
            {
                cout << "false\n";
            }
        }

		if (command == "next")
		{
			Node *res = bstNext(value);

			if (res == NULL)
            {
                cout << "none\n";
            }
			else
            {
                cout << res->key << "\n";
            }
		}

		if (command == "prev")
		{
			Node *res = bstPrev(value);

			if (res == NULL)
            {
                cout << "none\n";
            }
			else
            {
                cout << res->key << "\n";
            }
		}
	}

	return 0;
}

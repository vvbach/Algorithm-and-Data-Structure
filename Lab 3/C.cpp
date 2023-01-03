#include <iostream>
#include <string>
#include <malloc.h>

using namespace std;

struct Node {
    char data;
    struct Node *next;
};

typedef struct Node node;

struct Stack {
    struct Node *top;
} s;

void initStack(){
    s.top = NULL;
}

void push(char data){
    node* p = (node*)(malloc(sizeof(node)));
    p->data = data;
    p->next = NULL;
    if (s.top == NULL){
        s.top = p;
    }
    else {
        p->next = s.top;
        s.top = p;
    }
}

void pop(){
    node *p = s.top;
    s.top = s.top->next;
    free(p);
}

void deleteStack(){
    while(s.top != NULL){
        pop();
    }
}

int isEmpty(){
    if (s.top == NULL){
        return 1;
    } 
    return 0;
    
}

int main(){
    initStack();
    string x; 
    while(getline(cin,x)){
        for (int i = 0; i < x.size(); i++){
            if (s.top != NULL && ((s.top->data == '[' && x[i] == ']') || (s.top->data == '(' && x[i] == ')'))){
                pop();
            }
            else{
                push(x[i]);
            }
        }
        if (isEmpty()){
                cout << "YES" << endl;
        }
        else {
                cout << "NO" << endl;
        } 
        deleteStack();
    }
    return 0;
}
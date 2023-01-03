#include <iostream>
#include <string>
#include <malloc.h>

using namespace std;

struct node {
    int data;
    node *next;
};


struct Stack {
    node *top;
} s;

void initStack(){
    s.top = NULL;
}

void push(int data){
    node* p = new node;
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

int pop(){
    if (s.top == NULL){
        return '\0';
    }
    node *p = s.top;
    s.top = s.top->next;
    int d = p->data;
    free(p);
    return d;
}



int main(){
    initStack();
    char c; 
    int ans = 0;
    int a, b;
    while(cin >> c){
        if (c == '+'){
            a = pop();
            b = pop();
            push(a + b);
        }
        else if (c == '-'){
            b = pop();
            a = pop();
            push(a - b);
        }
        else if (c == '*'){
            a = pop();
            b = pop();
            push(a * b);
        }
        else {
            push(c - '0');
        }
    }
    cout << pop() << endl;
    return 0;
}
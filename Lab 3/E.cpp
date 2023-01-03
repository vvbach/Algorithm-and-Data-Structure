#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
    int max;
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
        p->max = data;
        s.top = p;
    }
    else {
        p->next = s.top;
        if (data > s.top->max){
            p->max = data;
        }
        else {
            p->max = s.top->max;
        }
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initStack();
    int n; cin >> n;
    string o;
    int x;
    for (int i = 0; i < n ; i++){
        cin >> o;
        if (o == "+"){
            cin >> x;
            push(x);
        }
        else if (o == "-"){
            pop();
        }
        else {
            cout << s.top->max << endl;
        }
    }
    return 0;
}
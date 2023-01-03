#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;

struct Stack {
    struct Node *top;
} s;

void initStack(){
    s.top = NULL;
}

void push(int data){
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
    printf("%d\n", s.top->data);
    s.top = s.top->next;
}


int main(){
    initStack();
    int n; 
    scanf("%d", &n);
    int i;
    char c;
    int x;
    for (i = 0; i < n; i++){
        scanf("\n%c", &c);
        if (c == '+'){
           scanf("%d", &x);
           push(x); 
        }
        else {
            pop();
        }
    }
    return 0;
}
#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;



struct Queue {
    struct Node *head, *tail;
} q;

void initQueue(){
    q.head = NULL;
    q.tail = NULL;
}

void enqueue(int data){              
    node* p = (node*)(malloc(sizeof(node)));
    p->data = data;
    p->next = NULL;

    if (q.head == NULL){              
        q.head = p;
        q.tail = p;
    }
    else {
        q.tail->next = p;
        q.tail = p;
    }
}

void dequeue(){
    printf("%d\n", q.head->data);
    q.head = q.head->next;
}

int main(){
    initQueue();
    int n; 
    scanf("%d", &n);
    int i;
    char c;
    int x;
    for (i = 0; i < n; i++){
        scanf("\n%c", &c);
        if (c == '+'){
           scanf("%d", &x);
           enqueue(x); 
        }
        else {
            dequeue();
        }
    }
    return 0;
}
#include <iostream>

using namespace std;

struct Node {
    int data;
    int line;
} heap[1000000];


int parent(int i){
    return (i - 1) / 2;
}

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

void shiftUp(int i){
    while(i > 0 && heap[parent(i)].data > heap[i].data){
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void shiftDown(int i, int size){
    int min = i;
    if (left(i) < size && heap[left(i)].data < heap[min].data){
        min = left(i);
    }
    if (right(i) < size && heap[right(i)].data < heap[min].data){
        min = right(i);
    }
    if (min != i){
        swap(heap[min], heap[i]);
        shiftDown(min, size);
    }
}

void insert(int value, int line, int &size){
    size++;
    heap[size - 1].data = value;
    heap[size - 1].line = line;
    shiftUp(size - 1);
}

void extractMin(int &size){
    if(size == 0){
        cout << "*" << endl;
        return;
    }
    int min = heap[0].data;
    cout << heap[0].data << endl;
    
    heap[0] = heap[size - 1];
    size--;
    shiftDown(0, size);
}

int findKey(int line, int size){
    for (int i = 0; i < size; i++){
        if (heap[i].line == line){
            return i;
        }
    }
    return -1;
}

void decreaseKey(int i, int value){
    heap[i].data = value;
    shiftUp(i);
}

int main(){
    int size = 0;
    int line = 0;
    string command;
    while (cin >> command){
        line++;
        if (command == "push"){
            int value;
            cin >> value;
            insert(value, line, size);
        } 
        else if (command == "extract-min"){
            extractMin(size);
        }
        else if (command == "decrease-key"){
            int l, v;
            cin >> l >> v;
            decreaseKey(findKey(l, size), v);
        }
    }
}
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000000;

vector<pair<int, int>> table(MAXN);
bool occupied[MAXN] = {0};
int arr[MAXN];

int hashFunc(int key, int i){
    return (key + i) % MAXN;
}

void insert(int element, int index){
    int i = 0;
    bool inserted = false;
    int key;
    while(!inserted){
        key = hashFunc(abs(element - index), i * i);
        i++;
        if (!occupied[key]){
            table[key] = {element, index};
            inserted = true;
            occupied[key] = true;
        }
    }
}

int search(int element, int index){
    int i = 0;
    bool found = false;
    int key;
    int count = 0;
    while(!found){
        key = hashFunc(abs(element - index), i * i);
        i++;
        if (table[key].first == element && table[key].second == index){
            found = true;
        } else {
            if (table[key].first - table[key].second == element - index){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n; cin >> n;
    int a;
    for (int i = 0; i < n; i++){
        cin >> a;
        insert(a, i);
        arr[i] = a;
    }
    int count = 0;
    for (int i = 0; i < n; i++){
        count += search(arr[i], i);
    }
    cout << count;
    return 0;
}
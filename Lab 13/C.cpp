#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 1000000;
unsigned int n;
vector<vector<unsigned int>> table1(MAXN);
vector<vector<unsigned int>> table2(MAXN);

unsigned int hashFunc(unsigned int key){
    return key % MAXN;
}

void insert(unsigned int k, vector<vector<unsigned int>> &table){
    table[hashFunc(k)].push_back(k);
}

int main(){
    cin >> n;
    unsigned int a;
    for (int i = 0; i < n; i++){
        cin >> a;
        int k = hashFunc(a);
        table1[k].push_back(a);
        
    }
    for (int i = 0; i < n; i++){
        cin >> a;
        int k = hashFunc(a);
        table2[k].push_back(a);
        
    }
    bool check = true;
    for (int i = 0; i < MAXN; i++){
        if (table1[i].size() != table2[i].size()){
            check = false;
            break;
        }
        if (table1[i].size() % 2 == 0) continue;
        else if (table1[i][0] != table2[i][0]){
            check = false;
            break;
        }
    }
    cout << (check ? "YES" : "NO");
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1000000;
vector<vector<int>> hashTable(MAX);

int hashFunc(vector<int> &s, int jump){
    
    int hashValue = 0;
    for (auto i = s.begin(); i != s.end(); i++){
        hashValue ^= *i;
    }
    return (hashValue + jump) % MAX ;
}

void insert(vector<int> &s){
    int i = 0;
    bool inserted = false;
    int key;
    sort(s.begin(), s.end());
    while(!inserted){
        key = hashFunc(s, i * i);
        i++;
        if (hashTable[key].size() == 0){
            inserted = true;
            hashTable[key] = s;
        }
    }
}

bool search(vector<int> &s){
    int i = 0;
    bool found = false;
    int key;
    sort(s.begin(), s.end());
    while(!found){
        key = hashFunc(s, i * i);
        i++;
        if (hashTable[key] == s){
            found = true;
            return true;
        }
        if (hashTable[key].size() == 0){
            return false;
        }
    }
    return false;
}

bool check(int mid, int n, int m, vector<int> &s1, vector<int> &s2){
    hashTable.clear();
    for (int i = 0; i <= n - mid; i++){  
        vector<int> s;
        s.assign(s1.begin() + i, s1.begin() + i + mid);
        insert(s);
    }
    for (int i = 0; i <= m - mid; i++){  
        vector<int> s;
        s.assign(s2.begin() + i, s2.begin() + i + mid);
        if (search(s)) return true;
    }
    return false;
}

int BinarySearch(int n, int m, vector<int> &s1, vector<int> &s2){
    int mid;
    int ans = 0;
    int l = 0; int r = min(m, n);
    while (l <= r){
        mid = (l + r) / 2;
        if (check(mid, n, m, s1, s2)){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> s1(n);
    for (int i = 0; i < n; i++){
        cin >> s1[i];
    }
    int m; cin >> m;
    vector<int> s2(m);
    for (int i = 0; i < m; i++){
        cin >> s2[i];
    }
    cout << BinarySearch(n, m, s1, s2);
}
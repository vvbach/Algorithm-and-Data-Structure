#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

typedef unsigned long long ll;

int n;
int bucketSize = 3000000;

ll hashFunc(int function, ll key){
    switch (function)
    {
    case 1:{
        return key % bucketSize;
    }
    
    case 2:{
        const double A = 0.6180339887f;
        return (ll)(double(bucketSize) * fmod(double(key) * A, 1.0f));
    }
    }
    return 1;
}

ll hashString(string s){
    ll hash = 0;
    for (int i = 0; i < s.length(); i++)
    	hash = (hash * 1153 + s[i] - 'a' + 1) % 1000000003;
    return hash;
}

void Insert(vector<ll> &s, string task){
    ll hashS = hashString(task);
    ll index1 = hashFunc(1, hashS);
    if (s[index1] == -1) {
        s[index1] = hashS;
        return;
    }
    ll index2 = hashFunc(2, hashS);
    if (s[index2] == -1) {
        s[index2] = hashS;
        return;
    }
    if (s[index1] == hashS && s[index2] == hashS) return;
    ll attemp = 100;
    while(attemp > 0){
        ll newHashS = s[index1];
        s[index1] = hashS;
        hashS = newHashS;

        index1 = hashFunc(1, hashS);
        if (s[index1] == -1) {
            s[index1] = hashS;
            return;
        }
        index2 = hashFunc(2, hashS);
        if (s[index2] == -1) {
            s[index2] = hashS;
            return ;
        }
        if (s[index1] == hashS && s[index2] == hashS) return;
        attemp--;
    }
}

bool Search(vector<ll> &s, string task){
    ll hashS = hashString(task);
    ll index1 = hashFunc(1, hashS);
    if (s[index1] == hashS) {
        return true;
    }
    ll index2 = hashFunc(2, hashS);
    if (s[index2] == hashS) {
        return true;
    }
    return false;
}


int main(){
    int point[3] = {0, 0 ,0};
    vector<vector<ll>> s(2, vector<ll>(bucketSize, -1));
    string data;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> data;
        Insert(s[0], data);
        point[0] += 3;
    }
    for (int i = 0; i < n; i++){
        cin >> data;
        Insert(s[1], data);
        if (Search(s[0], data)){
            point[0] -= 2;
            point[1] += 1;
        }
        else {
            point[1] += 3;
        }
    }
    for (int i = 0; i < n; i++){
        cin >> data;
        bool check_0 = Search(s[0], data);
        bool check_1 = Search(s[1], data);
        if (check_0 && check_1){
            point[0] -= 1;
            point[1] -= 1;
        }
        else if(check_0){
            point[0] -= 2;
            point[2] += 1;
        }
        else if(check_1){
            point[1] -= 2;
            point[2] += 1;
        }
        else {
            point[2] += 3;
        }
    }
    for(int i = 0; i < 3; i++){
        cout << point[i] << " ";
    }
    return 0;
}
#include <iostream>

using namespace std;

void countingSort(string s[100], int n, int m, int k){
    int character[26];
    for (int i = 0; i < 26; i++){
        character[i] = 0;
    }
    for (int i = 0; i < n; i++){
        character[s[i][m - k] - 97] += 1; 
    }
    
    for (int i = 1; i < 26; i++){
        character[i] += character[i - 1];
    }
    
    string temp[10000];
    for (int i = n - 1; i >= 0; i--){
        temp[character[s[i][m - k] - 'a'] - 1] = s[i];
        character[s[i][m - k] - 'a']--;
    }

    for (int i = 0; i < n; i++){
        s[i] = temp[i];
    }
}

int main(){
    int n, m, k; cin >> n >> m >> k;
    string str[10000];
    for (int i = 0; i < n; i++){
        cin >> str[i];
    }
    for (int i = 1; i <= k; i++){
        countingSort(str, n, m ,i);
    }
    for(int i = 0; i < n; i++){
        cout << str[i] << endl;
    }
    return 0;
}
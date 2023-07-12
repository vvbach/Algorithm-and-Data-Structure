#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPowerOf2(int n){
    return !(n & (n - 1));
}

string decoding(string s){
    string ans = "";
    int length = (int)log2(s.length()) + 1;
    vector<int> control_bit(length, 0);
    for (int i = 0; i < s.length(); i++){
        if (isPowerOf2(i + 1)){
            continue;
        }
        for (int j = 0; j < length; j++){
            if ((1 << j) & (i + 1)){
                control_bit[j] ^= s[i] - '0';
            }
        }  
    }
    vector<int> wrong_control_bit;
    for (int i = 0; i < length; i++){
        if (control_bit[i] != (s[pow(2, i) - 1] - '0')){
            wrong_control_bit.push_back(pow(2, i));
        }
    }
    int wrong_bit = 0;
    for (int i = 0; i < wrong_control_bit.size(); i++){
        wrong_bit += wrong_control_bit[i];
    }
    if (wrong_bit != 0){    
        s[wrong_bit - 1] = '0' + '1' - s[wrong_bit - 1];
    }
    for (int i = 0; i < s.length(); i++){
        if (isPowerOf2(i + 1)) continue;
        ans += s[i];
    }
    return ans;
}

int main(){
    int t; cin >> t;
    string s;
    while (cin >> s){
        cout << decoding(s) << endl;
    }
    return 0;
}
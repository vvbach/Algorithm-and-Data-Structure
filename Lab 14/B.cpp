#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int n = s.length();
    vector<int> prefix(n, 0);
    int i = 1;
    int len = 0;
    while (i < n){
        if (s[len] == s[i]){
            len++;
            prefix[i] = len;
            i++;
        }
        else {
            if (len != 0){
                len = prefix[len - 1];
            }
            else {
                prefix[i] = len;
                i++;
            }
        }
    }
    for (auto i : prefix) cout << i << " ";
}
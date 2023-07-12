#include <iostream>
#include <regex>

using namespace std;

regex checkRegex("^([A-Z][a-z]*){3}\\d{2}((\\+7((\\(\\d{3}\\)((\\d{3}-\\d{4})|(-\\d{3}-\\d{2}-\\d{2})))|(\\d{10})))|((7|8)\\d{10}))g\\.[A-Z]{3}ul\\.[A-Z][a-z]*d\\.\\d{2,}$");

int main(){
    string N;
    getline(cin, N);
    int n =  stoi(N);
    for (int i = 0; i < n; i++){
        string S;
        getline(cin, S);
        string s;
        for (auto c : S) {
            if (c != ' ' && c != ','){
                s.push_back(c);
            }
        }
        if (regex_match(s, checkRegex)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
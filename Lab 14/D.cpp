#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
    map<char, Node*> child;
    int endOfWord;
    int numOfWord;
};

void insert(Node* root, string s){
    Node* p = root;
    for (int i = 0; i < s.length(); i++){
        char c = s[i];
        if (p->child.find(c) == p->child.end()) p->child.insert({c, new Node()});
        p = p->child[c];
        p->numOfWord++;
    }
    p->endOfWord++;
}

void dfs(Node* root, int& k, string &s){
    for (auto i : root->child){
        if (k > i.second->numOfWord) {
            k -= i.second->numOfWord;
            continue;
        }
        s += i.first;
        if (i.second->endOfWord != 0) k -= i.second->endOfWord;
        if (k <= 0) return;
        dfs(i.second, k, s);
        if (k <= 0) return;
        s.pop_back();
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    Node* root = new Node();
    int n; cin >> n;
    string query;
    for (int i = 0; i < n; i++){
        cin >> query;
        if (isdigit(query[0])){
            string s = "";
            int base = 1;
            int num = 0;
            for (int i = query.length() - 1; i >= 0; i--){
                num += (query[i] - '0') * base;
                base *= 10;
            }
            dfs(root, num, s);
            cout << s << endl;
        } else {
            insert(root, query);
        }
    }

}
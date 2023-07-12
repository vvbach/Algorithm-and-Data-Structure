#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10001;

pair<int, int> table[MAXN][1000];
int num[MAXN];
int sum[MAXN];
bool occupied[MAXN][MAXN];
int p[MAXN][101];

int hashFunc(int key, int i){
    key = key + i;
    key *= key;
    key >>= 11;
    key %= 1024;
    return key % 1000; 
}

void insert(int group,int isu, int point){
    int i = 0;
    bool inserted = false;
    int key;
    while(!inserted){
        key = hashFunc(isu, i * i);
        i++;
        if (!occupied[group][key]){
            table[group][key] = {isu, point};
            inserted = true;
            occupied[group][key] = true;
        }
    }
    num[group]++;
    sum[group] += point;
    p[group][point]++;
}

void remove(int group, int isu){
    int i = 0;
    bool found = false;
    int key;
    int count = 0;
    int point;
    while(!found){
        key = hashFunc(isu, i * i);
        i++;
        if (table[group][key].first == isu){
            point = table[group][key].second;
            found = true;
            table[group][key].first = 0;
            table[group][key].second = 0;
            occupied[group][key] = false;
        } 
    }
    num[group]--;
    sum[group] -= point;
    p[group][point]--;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int m, q; cin >> m >> q;
    char c;
    int group, isu, point;
    for (int i = 0; i < q; i++){
        cin >> c;
        if (c == '+'){
            cin >> group >> isu >> point;
            insert(group, isu, point);
        }
        else if (c == '-'){
            cin >> group >> isu;
            remove(group, isu);
        }
        else if (c == 'a'){
            cin >> group;
            cout << sum[group] / num[group] << "\n";
        }
        else if (c == 'm'){
            cin >> group;
            for (int i = 100; i >= 0; i--){
                if (p[group][i] > 0){
                    cout << i << "\n";
                    break;
                }
            }
        }
    }
}
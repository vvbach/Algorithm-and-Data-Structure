#include <iostream>
#include <vector>

typedef long long ll;

const int base = 31;
const ll MOD = 1000000003;
const ll maxn = 1000111;

using namespace std;

ll POW[maxn], hashT[maxn];


ll getHashT(int i,int j) {
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}


int main() {
    int N, Q; cin >> N >> Q;
    string T; cin >> T;

    int lenT = T.size();
    T = " " + T;
    POW[0] = 1;

    for (int i = 1; i <= lenT; i++)
    	POW[i] = (POW[i - 1] * base) % MOD;

    for (int i = 1; i <= lenT; i++)
    	hashT[i] = (hashT[i - 1] * base + T[i] - 'a' + 1) % MOD;
    int count = 0;
    int a, b, c;
    for (int q = 0; q < Q; q++){
        cin >> a >> b >> c;
        if (getHashT(a, a + c - 1) == getHashT(b, b + c - 1)) count++;
    }
    cout << count;
}
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<bool>> GrayCode((int)pow(2, n) + 1, vector<bool>(n + 1, false));
    GrayCode[1][n] = 0;
    GrayCode[2][n] = 1;
    int p = 2;
    for (int i = 2; i <= n; i++){
        int t = p;
        p *= 2;
        for (int k = (p / 2 + 1); k <= p; k++){
            GrayCode[k] = GrayCode[t];
            GrayCode[t][n + 1 - i] = 0;
            GrayCode[k][n + 1 - i] = 1;
            t--;
        }
    }

    for (int i = 1; i <= (int)pow(2, n); i++){
        for (int j = 1; j <= n; j++){
            cout << GrayCode[i][j];
        }
        cout << endl;
    }
}
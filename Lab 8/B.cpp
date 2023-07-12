#include <iostream>
#include <vector>

using namespace std;

struct segment {
    char c;
    int length;
    segment(char c, int length){
        this->c = c;
        this->length = length;
    }
};

int main(){
    int n,m,k;
    string s1, s2;
    cin >> n >> m >> k;
    cin >> s1;
    cin >> s2;
    vector<segment> decode1, decode2;
    int num = 0;
    char c;
    for (int i = 0; i < s1.length(); i++){
        if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z')){
            if (i != 0) {
                decode1.push_back(segment(c, num));
            }
            num = 0;
            c = s1[i];
        }
        else {
            num = num * 10 + (s1[i] - '0');
        }
    }
    decode1.push_back(segment(c, num));

    for (int i = 0; i < s2.length(); i++){
        if ((s2[i] >= 'a' && s2[i] <= 'z') || (s2[i] >= 'A' && s2[i] <= 'Z')){
            if (i != 0) decode2.push_back(segment(c, num));
            num = 0;
            c = s2[i];
        }
        else {
            num = num * 10 + (s2[i] - '0');
        }
    }
    decode2.push_back(segment(c, num));

    int i = 0, j = 0, diff = 0;
    while(i < decode1.size() || j < decode2.size()){
        int diff_seg = min(decode1[i].length, decode2[j].length);
        decode1[i].length -= diff_seg;
        decode2[j].length -= diff_seg;
        if (decode1[i].c != decode2[j].c){  
            diff += diff_seg;
        }
        if (decode1[i].length == 0) i++;
        if (decode2[j].length == 0) j++;
    }
    if (diff < k) cout << "Yes";
    else cout << "No";
    return 0;
}
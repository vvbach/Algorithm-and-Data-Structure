#include <iostream>

using namespace std;

struct Fridge
{
    int milk;
    int meat;
    int chesse;
    int snack;
};


int main(){
    struct Fridge f1 = {2, 3, 4 ,5};
    struct Fridge f2 = {1, 2, 4 ,5};
    f1.meat += 2;
    f2.chesse -= 1;
    return 0;
}
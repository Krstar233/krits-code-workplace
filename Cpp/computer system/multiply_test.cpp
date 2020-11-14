#include <iostream>
using namespace std;

int main(){
    int multiplier = 1001;
    int multiplicand = 1000;
    int product = 0;

    //cin >> multiplicand >> multiplier;

    int count = 0;
    while (count < 32){
        if (multiplier & 1){
            product += multiplicand;
        }
        multiplicand <<= 1;
        multiplier >>= 1;
        count++;
    }
    cout << product << endl;
}
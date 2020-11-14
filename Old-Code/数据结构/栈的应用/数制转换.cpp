#include "Stack.h"
#include <iostream>

using namespace std;

int main(){
    Stack<int> stack;
    int n;

    cin >> n;

    while (n){
        stack.push(n % 8);
        n /= 8;
    }
    while(!stack.empty()){
        cout << stack.pop();
    }
    cout << endl;
}
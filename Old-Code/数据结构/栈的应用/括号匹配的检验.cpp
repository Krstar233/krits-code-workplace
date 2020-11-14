#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

bool push_pop(Stack<string> &stack, string s){
    if (s == "(" || s == "[" || s == "{"){
        stack.push(s);
        return true;
    }
    else if (!stack.empty()){
        string s2 = stack.pop();
        if (s == ")"){
            return s2 == "(";
        }
        if (s == "]"){
            return s2 == "[";
        }
        if (s == "}"){
            return s2 == "{";
        }
    }
    else
        return false;
}

int main(){
    Stack<string> stack;
    string s;
    bool ok = true;
    
    while(cin >> s){
        if (!push_pop(stack, s)){
            ok = false;
            break;
        }
    }

    if (!stack.empty())
        ok = false;
    
    if (ok){
        cout << "OK!" << endl;
    }
    else{
        cout << "ERROR!" << endl;
    }
}

/*
测试数据
input:
[ ( [ ] [ ] ) ]

) ( ) [ ]

( ) [

output:
OK!

ERROR!

ERROR!
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include "Stack.h"

using namespace std;

double String_to_double(string s){
    double d;
    bool fushu = false;
    bool behind_point = false;
    int xiaoshu = 0;

    if (s[0] == '-'){
        s.erase(s.begin());
        fushu = true;
    }

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '.'){
            behind_point = true;
            continue;
        }
        if (!behind_point){
            d *= 10;
            d += (s[i] - '0');
        }
        else{
            xiaoshu++;
            d += ((s[i] - '0') * pow(10, -xiaoshu));
        }
    }
    if (fushu)
        d = -d;
    return d;
}

char Precede(string a, string b){
    if (a == "(" && b == ")")
        return '=';
    else if (a == "(" || b == "(")
        return '<';
    else if ((a == "+" || a == "-") && (b == "*" || b == "/"))
        return '<';
    else if ((a == "*" || a == "/") && (b == "+" || b == "-"))
        return '>';
    else
        return '>';
}

bool IsCul(string s){
    string cul[] = {"+", "-", "*", "/", "(", ")"};
    const int NUM = 6;

    for (int i = 0; i < NUM; i++){
        if (s == cul[i])
            return true;
    }
    return false;
}

double Calculate(string s, double a, double b){
    if (s == "+")   return a+b;
    if (s == "-")   return a-b;
    if (s == "*")   return a*b;
    if (s == "/")   return a/b;
}

void solve(){
    string s;
    Stack<string> cul;
    Stack<double> value;
    
    while (cin >> s && s != "="){
        if (!IsCul(s)){
            value.push(String_to_double(s));
        }
        else{
            if (cul.empty()){
                cul.push(s);
                continue;
            }
            if (s == ")"){
                while (cul.GetTop() != "("){
                    value.push(Calculate(cul.pop(), value.pop(), value.pop()));
                }
                cul.pop();
                continue;
            }

            switch (Precede(cul.GetTop(), s)){
                case '<':   cul.push(s);   break;
                case '=':   cul.pop();     break;
                case '>':   value.push(Calculate(cul.pop(), value.pop(), value.pop())); 
                            cul.push(s);
            }
        }
    }
    while (!cul.empty()){
        value.push(Calculate(cul.pop(), value.pop(), value.pop()));
    }
    cout << value.pop() << endl;
}

int main(){
    solve();
}
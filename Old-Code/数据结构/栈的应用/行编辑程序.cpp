#include "Stack.h"
#include <iostream>

using namespace std;

void LineEdit(){
    Stack<char> stack;
    char ch;

    ch = getchar();
    while (ch != EOF){
        while (ch != EOF && ch != '\n'){
            switch (ch){
                case '#': stack.pop(); break;
                case '@': stack.clear(); break;
                default:  stack.push(ch);
            }
            ch = getchar();
        }
        stack.travelFromBottom();
        stack.clear();
        if (ch != EOF) ch = getchar();
    }
}

int main(){
    LineEdit();
}
/*
测试数据:
whli##ilr#e(s#*s)
        outcha@putchar(*s=#++)

 */
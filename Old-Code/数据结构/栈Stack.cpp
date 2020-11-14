#include <iostream>

using namespace std;

template<class T>
class Stack{

    int size;//栈空间大小
    int length;//栈元素个数

    T *top;//栈顶指针, 指向栈顶元素的后一个位置
    T *base;//栈底指针

public:
    Stack(): size(1), length(0){
        base = new T[1];
        top = base;
    }
    
    void push(T e){
        if (size <= length){
            resize(size*2);
        }//保证有足够的栈空间
        *top = e;
        top++;
        length++;
    }//入栈

    void resize(int rsize){
        T *p = base;
        T *rbase = new T[rsize];
        T *rtop = rbase;
        size = rsize;

        while (p != top){
            *rtop = *p;
            rtop++;
            p++;
        }
        delete[] base;
        base = rbase;
        top = rtop;
    }//重新设置栈的存储大小
    T pop(){
        T e = *(--top);
        length--;

        if (length && size / length >= 4){
            resize(size / 2);
        }
        return e;
    }//出栈

    T GetTop(){
        return *(top-1);
    }//获取栈顶元素但不出栈

    bool empty(){
        return length == 0;
    }//查看栈是否为空

    int GetSize(){
        return size;
    }//获取栈空间的大小

    int GetLength(){
        return length;
    }//获取栈中元素的个数

    void travelFromBottom(){
        T *p = base;
        while(p != top){
            cout << *(p++);
            if (p != top)   cout << " ";
        }
        cout << endl;
    }//从栈底部历遍栈

    ~Stack(){
        delete[] base;
    }
};

int main(){
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.travelFromBottom();
    cout << stack.GetTop() << endl;

    while(!stack.empty()){
        cout << stack.pop() << " ";
    }
    cout << endl;
    cout << stack.GetSize() << endl;

    for (int i = 4; i <= 1000; i++){
        stack.push(i);
    }

    cout << stack.GetSize() << endl;
    cout << stack.GetLength() << endl;
}
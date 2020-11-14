#include <iostream>

using namespace std;

template<class T>
class SqQueue{
    T *base;
    int front;
    int rear;

public:
    SqQueue(){
        base = new T[100];
        if (!base){
            cout << "Over Memory" << endl;
            exit();
        }
        front = rear = 0;
    }

    int QueueLength(){

    }
};

int main(){

}
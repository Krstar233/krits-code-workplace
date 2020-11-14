#include <iostream>

using namespace std;

template<class T>
class Queue{
    class QNode{
    public:
        T data;
        QNode *next;

        QNode():next(NULL){}
        QNode(T e):data(e), next(NULL){}
    };

    QNode *front;
    QNode *rear;
    int length;


public:
    Queue():length(0){
        front = new QNode;
        rear = front;
    }

    void EnQueue(T e){
        QNode *node = new QNode(e);
        rear->next = node;
        rear = node;
        length++;
    }//进队

    T DeQueue(){
        QNode *p = front->next;
        T e = p->data;
        front->next = p->next;
        if (p == rear)
            rear = front;
        delete p;
        length--;
        return e;
    }//出队

    T GetFront(){
        return front->next->data;
    }//查看队顶

    bool Empty(){
        return length == 0;
    }//查看队列是否为空

    void clear(){
        QNode *p = front->next;

        while(p){
            QNode *q = p;
            p = p->next;
            delete q;
        }

        length = 0;
    }//清空队列

    int Length(){
        return length;
    }

    ~Queue(){
        clear();
        delete front;
    }
};

int main(){
    Queue<int> queue;

    for (int i = 0; i < 5; i++)
        queue.EnQueue(i);
    
    for (int i = 0; i < 5; i++)
        cout << queue.DeQueue() << endl;
    
    if (queue.Empty()){
        cout << "EMPTY" << endl;
    }

    cout << "------------" << endl;

    queue.EnQueue(233);
    cout << queue.GetFront() << endl;

    if (!queue.Empty())
        cout << "!EMPTY" << endl;
    
    cout << queue.Length() << endl;
}
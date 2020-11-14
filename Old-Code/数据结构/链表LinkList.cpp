#include <iostream>

using namespace std;

template <class T>
class LinkList{

    class Node{
    public:
        T data;
        Node* next;
        Node(): next(NULL){}
        Node(T e):data(e), next(NULL){}
    };

    Node *head;
    int length;

public:
    LinkList(){
        head = new Node;
        length = 0;
    }

    void push_back(T e){
        ListInsert(length+1, e);
    }//尾插

    Node* GetElem(int i){
        if (i > length || i < 0)
            return 0;
        Node *p = head;
        int j = 0;

        while(p && j < i){
            p = p->next;
            j++;
        }
        return p;
    }//获取指向第i个元素的指针, i为0时返回头指针

    void ListInsert(int i, T e){
        Node *p = GetElem(i-1);
        if (p){
            Node *node = new Node(e);
            node->next = p->next;
            p->next = node;
            length++;
        }//确保p有效
        else{
            cout << "Insert failed" << endl;
        }
    }//在第i个元素的位置插入元素e

    void ListDelete(int i){
        Node *p = GetElem(i-1);
        if (p){
            Node *q = p->next;
            p->next = q->next;
            delete q;
            length--;
        }
        else {
            cout << "Delete failed" << endl;
        }
    }// 删除第i个元素

    void MergeList(LinkList &Lb){
        Node *pa = head->next;
        Node *pb = Lb.head->next;
        Node *pc = head;

        while(pa && pb){
            if (pa->data <= pb->data){
                pc->next = pa;
                pa = pa->next;
                pc = pc->next;
            }
            else {
                Node *node = new Node(pb->data);
                pc->next = node;
                pb = pb->next;
                pc = pc->next;
            }
        }

        if (pa){
            pc->next = pa;
        }
        while(pb){
            Node *node = new Node(pb->data);
            pc->next = node;
            pb = pb->next;
            pc = pc->next;
        }// 将剩余链连接

        length += Lb.length;

    }//与另一个链表归并

    void print(){
        int i = 1;
        Node *p = head->next;

        while(p && i <= length){
            cout << p->data;
            p = p->next;
            i++;
            if (p)  cout << " ";
        }
        cout << endl;
    }//打印输出

    void clear(){
        Node *p = head->next;

        while(p){
            Node *q = p;
            p = p->next;
            delete q;
        }
        length = 0;
    }
    ~LinkList(){
        clear();
        delete head;
    }
};// 线性链表，下标从1开始

int main(){
    LinkList<int> l;

    for (int i = 1; i <= 10; i++)
        l.push_back(i);
    l.print();

    l.ListInsert(1, 0);
    l.print();

    l.ListDelete(5);
    l.print();

    LinkList<int> lb;
    for (int i = 3; i <= 12; i++)
        lb.push_back(i);
    l.MergeList(lb);
    l.print();

    l.clear();
    l.print();
}
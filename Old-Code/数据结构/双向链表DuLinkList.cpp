#include <iostream>

using namespace std;

template <class T>
class DuLinkList{

    class Node{
    public:
        T data;
        Node* next;
        Node* prior;
        Node(): next(NULL), prior(NULL){}
        Node(T e):data(e), next(NULL), prior(NULL){}
    };

    Node *head;//头指针
    Node *tail;//尾指针
    int length;

public:
    DuLinkList(){
        head = new Node;
        length = 0;
        tail = head;
    }

    void push_back(T e){
        Node *node = new Node(e);
        tail->next = node;
        node->prior = tail;
        tail = node;
        length++;
    }

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
            if (node->next){
                node->next->prior = node;
            }
            p->next = node;
            node->prior = p;
            length++;

            if (p == tail){
                tail = p->next;
            }
        }//确保p有效
        else{
            cout << "Insert failed" << endl;
        }
    }//在第i个元素的位置插入元素

    void ListDelete(int i){
        Node *p = GetElem(i-1);
        if (p){
            Node *q = p->next;
            p->next = q->next;
            if (p->next)
                p->next->prior = p;
            else{
                tail = p;
            }
            delete q;
            length--;
        }
        else {
            cout << "Delete failed" << endl;
        }
    }// 删除第i个元素

    void MergeList(DuLinkList &Lb){
        Node *pa = head->next;
        Node *pb = Lb.head->next;
        Node *pc = head;

        while(pa && pb){
            if (pa->data <= pb->data){
                pc->next = pa;
                pa->prior = pc;
                pa = pa->next;
                pc = pc->next;
            }
            else {
                Node *node = new Node(pb->data);
                pc->next = node;
                node->prior = pc;
                pb = pb->next;
                pc = pc->next;
            }
        }

        if (pa){
            pc->next = pa;
            pa->prior = pc;
        }
        while(pb){
            Node *node = new Node(pb->data);
            pc->next = node;
            node->prior = pc;
            pb = pb->next;
            pc = pc->next;
        }// 将剩余链连接

        length += Lb.length;

        tail = GetElem(length);

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

    void reversePrint(){
        int i = 1;
        Node *p = tail;

        while(p && i <= length){
            cout << p->data;
            p = p->prior;
            i++;
            if (p)  cout << " ";
        }
        cout << endl;
    }

    void clear(){
        Node *p = head->next;

        while(p){
            Node *q = p;
            p = p->next;
            delete q;
        }
        length = 0;
        tail = head;
    }

    ~DuLinkList(){
        clear();
        delete head;
    }
};


int main(){
    DuLinkList<int> l;

    for (int i = 1; i <= 10; i++)
        l.push_back(i);
    l.print();
    l.reversePrint();

    l.ListInsert(1, 0);
    l.print();
    l.reversePrint();

    l.ListDelete(5);
    l.print();
    l.reversePrint();

    DuLinkList<int> lb;
    for (int i = 3; i <= 12; i++)
        lb.push_back(i);
    l.MergeList(lb);
    l.print();
    l.reversePrint();

    l.clear();
    l.print();
    l.reversePrint();
}
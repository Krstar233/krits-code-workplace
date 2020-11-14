#define ERROR -1
#define OVERMEMORY -2

#include <iostream>

using namespace std;

template<class T>
class List{
    T *elem;    //存储空间的基址
    int length; //当前顺序表长度
    int listsize; //当前分配空间的大小

public:
    List(){
        InitList(1);
    }
    List(int size){
        InitList(size);
    }
    List(const List &l){
        elem = new T[l.listsize];
        length = l.length;
        listsize = l.listsize;
        for (int i = 0; i < l.listsize; i++){
            elem[i] = l.elem[i];
        }
    }//拷贝构造函数

    ~List(){
        delete elem;
    }

    void InitList(int L){
        elem = new T[L];
        if (!elem){
            cout << "Over Memory!" << endl;
            exit(OVERMEMORY);
        }
        length = 0;
        listsize = L;
    }// 初始化链表

    void ListInsert(int i,const T &e){
        if (i < 0 || i > length)    return;
        if (length >= listsize)
            resize(listsize*2);
        
        T *p = &elem[i];
        for (T *q = &elem[length]; q > p; q--){
            *q = *(q-1);
        }
        *p = e;
        length++;
    }// 在下标为i的位置插入元素e

    void push_back(const T &e){
        ListInsert(length, e);
    }//在表末添加元素e

    void ListDelete(int i){
        if (i < 0 || i >= length)    return;

        T *end = &elem[length-1];
        for (T *p = &elem[i]; p != end; p++){
            *p = *(p+1);
        }
        length--;

        if (listsize / length >= 4){
            resize(listsize / 2);
        }//如果分配的空间太大，调整大小

    }//删除下标为i的元素
    void resize(int size){
        T *newelem = new T[size];
        if (!newelem){
            cout << "Over Memory!" << endl;
            exit(OVERMEMORY);
        }

        int count = 0;
        for (int i = 0; i < size; i++){
            if (i < length){
                newelem[i] = elem[i];
                count++;
            }
            else
                break;
        }
        delete elem;
        elem = newelem;
        listsize = size;
        length = count;
    }// 重新设置顺序表存储空间大小
    
    int LocateElem(const T &e){
        int i = 0;
        T *p = elem;
        while (i < length && *p != e){
            p++;
            i++;
        }
        if (i == length)
            return -1;
        return i;
    }//获取元素e的下标，如果有多个则返回下标最小的一个

    void MergeList(List &b){
        List c;

        T *pa = elem;
        T *pb = b.elem;

        c.resize(listsize+b.listsize);
        c.length = length + b.length;

        T *pc = c.elem;
        T *pa_last = &elem[length-1];
        T *pb_last = &b.elem[b.length-1];

        //归并
        while (pa <= pa_last && pb <= pb_last){
            if (*pa <= *pb){
                *pc = *pa;
                pa++;
                pc++;
            }
            else{
                *pc = *pb;
                pc++;
                pb++;
            }
        }
        while (pa <= pa_last){
            *pc = *pa;
            pc++;
            pa++;
        }//插入La剩余元素
        while (pb <= pb_last){
            *pc = *pb;
            pc++;
            pb++;
        }//插入Lb剩余元素

        *this = c;
    }// 与一个顺序表归并

    void print(){
        for (int i = 0; i < length; i++){
            cout << elem[i];
            if (i != length-1)
                cout << " ";
        }
        cout << endl;
    }

    T& operator[] (int i){
        return elem[i];
    }// 重载[]

    void operator= (const List &l){
        if (listsize)
            delete elem;
        elem = new T[l.listsize];
        length = l.length;
        listsize = l.listsize;
        for (int i = 0; i < l.listsize; i++){
            elem[i] = l.elem[i];
        }
    }// 重载赋值(深拷贝)

};//顺序表类, 下标从0开始


int main(){
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.ListInsert(0, 0);
    l.print();

    List<int> a;
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.ListDelete(1);
    a.print();
    
    a.MergeList(l);
    a.print();
}
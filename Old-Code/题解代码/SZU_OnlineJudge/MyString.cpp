#include <iostream>
#include <cstring>

using namespace std;

class MyString{
    char *base;
    int length;
    int size;

public:
    MyString(): length(0), size(1){
        base = new char[1];
        base[0] = '\0';
    }
    MyString(char* str, int len){
        base = new char[len+1];
        size = len+1;
        length = len;
        for (int i = 0; i <= len; i++){
            base[i] = str[i];
        }
    }
    MyString(char* str){
        int len = strlen(str);
        base = new char[len+1];
        size = len+1;
        length = len;
        for (int i = 0; i <= len; i++){
            base[i] = str[i];
        }
    }
    MyString(MyString &str){
        size = str.size;
        length = str.length;
        base = new char[size];
        for (int i = 0; i < size; i++){
            base[i] = str.base[i];
        }
    }
    ~MyString(){
        delete[] base;
    }
    friend MyString operator+ (const MyString& str1, const MyString& str2){
        char* newbase = new char[str1.length+str2.length+1];
        for (int i = 0; i < str1.length; i++){
            newbase[i] = base[i];
        }
        for (int i = 0; i <= str2.length; i++){
            newbase[i+str1.length] = str2.base[i];
        }
        MyString n_str(newbase, length+str2.length);
        return n_str;
    }
    MyString operator+ (const char* str){
        char* newbase = new char[length+strlen(str)+1];
        for (int i = 0; i < length; i++){
            newbase[i] = base[i];
        }
        for (int i = 0; i <= strlen(str); i++){
            newbase[i+length] = str[i];
        }
        MyString n_str(newbase);
        cout << "n_str:" << n_str.base << endl;
        return n_str;
    }
    void operator= (MyString str){
        length = str.length;
        size = str.size;
        delete[] base;
        base = new char[size];
        for (int i = 0; i < size; i++){
            base[i] = str.base[i];
        }
    }
    // MyString operator+= (MyString& str){
    //     MyString res = *this + str;
    //     return res;
    // }
    // MyString operator+= (char* str){
    //     MyString res = *this + str;
    //     return res;
    // }
    friend ostream& operator<< (ostream& out,const MyString &s){
        out << s.base;
        return out;
    }
};

int main(){
    char *str = "Hello World";
    char *str2 = "hi~";
    MyString s(str);
    MyString s1("23333");
    cout << s << " " << s1 << endl;
    cout << "----------------------" << endl;

    s = s1+s;
    cout << s << endl;

}
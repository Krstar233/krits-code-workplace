#include <vector>
#include <string>

using namespace std;

class OrderedStream {
public:
    vector<string> v;
    int pos;
    OrderedStream(int n) {
        pos = 1;
        v = vector<string>(n+5,"");
    }
    
    vector<string> insert(int id, string value) {
        vector<string> ret;
        v[id] = value;
        if (pos == id){
            while (v[pos] != ""){
                ret.push_back(v[pos]);
                pos++;
            }
        }
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
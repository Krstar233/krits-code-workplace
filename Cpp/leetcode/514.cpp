#include <string>
#include <queue>
#include <map>
#include <iostream>

#define INT_MAX 0x7fffffff;

using namespace std;

class Solution {
public:
    string key;
    int min_path;
    map<string, string> left_table;
    map<string, string> right_table;

    string left(string s){
        if (!left_table[s].empty())
            return left_table[s];
        string s_l = s.substr(1, s.length()-1) + s.at(0);
        left_table[s] = s_l;
        return s_l;
    }
    string right(string s){
        if (!right_table[s].empty())
            return right_table[s];
        string s_r = s.at(s.length()-1) + s.substr(0, s.length()-1);
        right_table[s] = s_r;
        return s_r;
    }
    void dfs(string node, int step, int index){
        if (index == key.length()){
            if (step < min_path)
                min_path = step;
            return;
        }
        if ((step / node.length()) >= key.length()){
            return;
        }
        cout << step << endl;
        if (node[0] == key[index]){
            step++;
            index++;
        }
        dfs(left(node), step+1, index);
        dfs(right(node), step+1, index);
    }
    int findRotateSteps(string ring, string key) {
        this->key = key;
        this->min_path = INT_MAX;
        dfs(ring,0,0);
        return min_path-1;
    }
};
int main(){
    Solution s;
    cout << s.findRotateSteps("godding","gd") << endl;
}
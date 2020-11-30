#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        map<char, int> m;

        for (int i = 0; i < S.length(); i++){
            m[S[i]]++;
        }

        vector<char> v(S.length());
        int index = 0;

        vector<pair<char, int>> v_p;
        for (map<char, int>::iterator it = m.begin(); it != m.end(); it++){
            char ch = it->first;
            int num = it->second;

            v_p.push_back(pair<char, int>(ch, num));
            
        }

        sort(v_p.begin(), v_p.end(), [&](pair<char,int> &a, pair<char,int> &b){
            return a.second > b.second;
        });

        for (int i = 0; i < v_p.size(); i++){
            char ch = v_p[i].first;
            int num = v_p[i].second;
            for (int j = 0; j < num; j++){
                v[index] = ch;
                index += 2;
                if (index >= S.length()){
                    index = 1;
                }
            }
        }

        for (int i = 0; i < S.length() - 1; i++){
            if (v[i] == v[i+1])
                return "";
        }

        string ret_str = "";

        for (int i = 0; i < v.size(); i++){
            ret_str += v[i];
        }

        return ret_str;
    }
};

int main(){

}
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> table;
        if (s.length() != t.length())
            return 0;
        int n = s.length();
        for (int i = 0; i < n; i++){
            table[s[i]]++;
            table[t[i]]--;
        }

        for (map<char, int>::iterator it = table.begin(); it != table.end(); it++){
            if (it->second != 0)
                return false;
        }
        return true;
    }
};
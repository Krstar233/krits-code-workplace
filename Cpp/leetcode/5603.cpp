#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;
        map<char, int> mp1, mp2;
        int n = word1.length();
        for (int i = 0; i < n; i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        if (mp1.size() != mp2.size())
            return false;
        priority_queue<int> ping1, ping2;
        for (int i = 0; i < 26; i++){
            char ch = 'a'+i;
            if (mp1[ch]){
                if (!mp2[ch])
                    return false;
                ping1.push(mp1[ch]);
                ping2.push(mp2[ch]);
            }
        }
        while (!ping1.empty() && !ping2.empty()){
            int top1 = ping1.top(); ping1.pop();
            int top2 = ping2.top(); ping2.pop();
            if (top1 != top2)
                return false;
        }
        return true;
    }
};
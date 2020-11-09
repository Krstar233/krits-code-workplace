#include <map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDeletions(string s) {
        map<char,int> table;
        vector<int> arr;
        map<int,bool> xl;
        int sum = 0; 
        for (int i = 0; i < s.length(); i++){
            table[s[i]]++;
        }
        for (map<char,int>::iterator it = table.begin(); it != table.end(); it++){
            int num = it->second;
            arr.push_back(num);
            
        }
        sort(arr.begin(), arr.end());
        for (auto num : arr){
            while (xl[num] && num != 0){
                num--;
                sum++;
            }
            if (num != 0)
                xl[num] = true;
        }
        return sum;
    }
};
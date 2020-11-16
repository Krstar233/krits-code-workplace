#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](vector<int>& a, vector<int>& b){
            if (a[1] != b[1])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> ans;

        for (int i = 0; i < people.size(); i++){
            vector<vector<int>>::iterator it;
            int count = 0;
            for (it = ans.begin(); it != ans.end(); it++){
                if (count == people[i][1]){
                    ans.insert(it, people[i]);
                    break;
                }
                else if (count < people[i][1] && (*it)[0] >= people[i][0]){
                    count++;
                }
            }
            if (it == ans.end()){
                ans.insert(it, people[i]);
            }
        }

        return ans;
    }
};
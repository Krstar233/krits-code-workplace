#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int x = newInterval[0];
        int y = newInterval[1];
        for (vector<vector<int>>::iterator it = intervals.begin(); it != intervals.end(); it++){
            int a_i = (*it)[0];
            int b_i = (*it)[1];
            if (x > b_i)
                continue;
            if (x >= a_i){
                if (y <= b_i){
                    break;
                }
            }
            else (*it)[0] = x;
            if (y > b_i){
                vector<vector<int>>::iterator it2 = it;
                for (;it2 != intervals.end(); it2++){
                    if (y <= (*it2)[1]){
                        break;
                    }
                }
                (*it)[1] = y < (*it2)[0] ? y : (*it2)[1];
                intervals.erase(it+1, it2);
                break;
            }
            break;
        }
        return intervals;
    }
};


int main(){

}
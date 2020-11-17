#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for (int r = 0; r < R; r++){
            for (int c = 0; c < C; c++){
                vector<int> v;
                v.push_back(r);
                v.push_back(c);
                ans.push_back(v);
            }
        }
        sort(ans.begin(), ans.end(), [&](vector<int>& a, vector<int>& b){
            int dis1 = abs(a[0]-r0)+abs(a[1]-c0);
            int dis2 = abs(b[0]-r0)+abs(b[1]-c0);
            return dis1 < dis2;
        });
        return ans;
    }
};

int main(){

}
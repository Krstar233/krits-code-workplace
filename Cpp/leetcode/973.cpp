#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct cmp{
        bool operator()(const vector<int> &p1, const vector<int> &p2){
            double distance1 = sqrt(p1[0]*p1[0]+p1[1]*p1[1]);
            double distance2 = sqrt(p2[0]*p2[0]+p2[1]*p2[1]);
            return distance1 > distance2;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        for (vector<int>& p : points){
            pq.push(p);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++){
            ans.push_back(pq.top()); pq.pop();
        }
        return ans;
    }
};
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> L(n+1), R(n+1);

        L[0] = 0;
        R[0] = 0;
        for (int i = 1; i <= n; i++){
            L[i] = L[i-1] + nums[i-1];
            R[i] = R[i-1] + nums[n-i];
        }
        for (int min_step = 1; min_step <= n; min_step++){
            for (int i = 0; i <= min_step; i++){
                if (L[i] + R[min_step-i] == x)
                    return min_step;
            }
        }
        return -1;
    }
};
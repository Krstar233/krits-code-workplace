#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for (i = n-1; i > 0; i--){
            if (nums[i-1] < nums[i])
                break;
        }
        if (i == 0){
            sort(nums.begin(), nums.end());
            return;
        }
        int j;
        for (j = n-1; j >= i; j--){
            if (nums[j] > nums[i-1])
                break;
        }
        int t = nums[j];
        nums[j] = nums[i-1];
        nums[i-1] = t;
        sort(nums.begin() + i, nums.end());
        return;
    }
};
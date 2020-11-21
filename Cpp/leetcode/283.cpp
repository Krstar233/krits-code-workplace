#include <vector>
using namespace std;
class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return;
        int head_zero = 0;
        int tail = 0;
        while (head_zero < n && nums[head_zero] != 0) head_zero++;
        tail = head_zero;
        while (tail < n){
            if (nums[tail] == 0){
                tail++;
                continue;
            }
            swap(nums, head_zero, tail);
            head_zero++;
            tail++;
        }
    }
};
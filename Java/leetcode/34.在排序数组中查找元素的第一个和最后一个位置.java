/*
 * @lc app=leetcode.cn id=34 lang=java
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = 0;
        int r = nums.length-1;
        while (l <= r){
            int mid = (l+r)/2;
            if (nums[mid] >= target){
                r = mid - 1;
                continue;
            }
            l = mid + 1;
        }
        System.out.println(l);
        return new int[1];
    }
}
// @lc code=end


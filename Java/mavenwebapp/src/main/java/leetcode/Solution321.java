package leetcode;

import java.util.Arrays;

class Solution321 {
    public int[] getMaxSubSequence(int[] nums, int k){
        int[] stack = new int[k];
        int top = 0;
        int leftRemoveNum = nums.length - k;
        for (int i = 0; i < nums.length; i++){
            while (top > 0 && leftRemoveNum > 0 && stack[top-1] < nums[i]) {
                top--;
                leftRemoveNum--;
            }
            if (top >= k) {
                leftRemoveNum--;
                continue;
            }
            stack[top] = nums[i];
            top++;
        }
//        if (top != k) {
//            System.out.println("!");
//            System.out.println(Arrays.toString(nums));
//            System.out.println(k);
//        }
        return stack;
    }
    public int[] merge(int[] sq1, int[] sq2){
        int n = sq1.length;
        int m = sq2.length;
        int p = 0;
        int q = 0;
        int[] sq = new int[n+m];
        int i;
        for (i = 0; p < n && q < m && i < n+m; i++){
            if (sq1[p] > sq2[q]){
                sq[i] = sq1[p];
                p++;
            }
            else if (sq1[p] < sq2[q]){
                sq[i] = sq2[q];
                q++;
            }
            else {
                int p1 = p;
                int q1 = q;
                while (p1 < n && q1 < m && sq1[p1] == sq2[q1]){
                    p1++;
                    q1++;
                }
                if (p1 < n && q1 < m){
                    if (sq1[p1] > sq2[q1]){
                        sq[i] = sq1[p];
                        p++;
                    }else {
                        sq[i] = sq2[q];
                        q++;
                    }
                }else if (p1 < n){
                    sq[i] = sq1[p];
                    p++;
                }else{
                    sq[i] = sq2[q];
                    q++;
                }
            }
        }
        for (;p < n && i < n+m; i++, p++){
            sq[i] = sq1[p];
        }
        for (;q < m && i < n+m; i++, q++){
            sq[i] = sq2[q];
        }
        return sq;
    }
    public boolean compare(int[] sq1, int[] sq2){
        if (sq1.length < sq2.length)
            return false;
        if (sq1.length > sq2.length)
            return true;
        int n = sq1.length;
        for (int i = 0; i < n; i++){
            if (sq1[i] > sq2[i])
                return true;
            if (sq1[i] < sq2[i])
                return false;
        }
        return false;
    }
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int[] maxSequence = new int[k];
        int n = nums1.length;
        int m = nums2.length;
        int start = Math.max(k-m, 0);
        int end = Math.min(k, n);
        for (int i = start; i <= end; i++) {
            int[] maxSubsequence1 = getMaxSubSequence(nums1, i);
            int[] maxSubsequence2 = getMaxSubSequence(nums2, k - i);
            int[] tmpSequence = merge(maxSubsequence1, maxSubsequence2);
            if (compare(tmpSequence, maxSequence)) {
                maxSequence = tmpSequence;
            }
        }
        return maxSequence;
    }
    public static void main(String[] args) {
        Solution321 s = new Solution321();
        int[] debug = new int[]{4, 0, 9, 9, 0, 5, 5, 4, 7};
        int debug_k = 4;
        s.getMaxSubSequence(debug, debug_k);


        int[] nums1 = new int[]{7,6,1,9,3,2,3,1,1};
        int[] nums2 = new int[]{4,0,9,9,0,5,5,4,7};
        int k = 9;
        int[] ans = s.maxNumber(nums1, nums2, k);
        for (int i : ans){
            System.out.print(i + " ");
        }System.out.println();
    }
}
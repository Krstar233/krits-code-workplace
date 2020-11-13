#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int p_odd = 1, p_even = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            if (A[i] % 2){
                ans[p_odd] = A[i];
                p_odd += 2;
            }else {
                ans[p_even] = A[i];
                p_even += 2;
            }
        }
        return ans;
    }
};
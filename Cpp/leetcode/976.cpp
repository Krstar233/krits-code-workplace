#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end(), [&](int a, int b){return a > b;});
        int n = A.size();
        for (int i = 0; i < n - 2; i++){
            if (A[i] < A[i+1] + A[i+2]){
                return A[i] + A[i+1] + A[i+2];
            }
        }
        return 0;
    }
};
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    static int sum_one(int n){
        int sum = 0;
        while (n != 0){
            if ((n & 1) == 1)
                sum++;
            n >>= 1;
        }
        return sum;
    }
    static bool comp(const int& a, const int &b){
        int sum_a = sum_one(a);
        int sum_b = sum_one(b);
        if (sum_a == sum_b)
            return a < b;
        return sum_a < sum_b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(),comp);
        return arr;
    }
};
int main(){

}
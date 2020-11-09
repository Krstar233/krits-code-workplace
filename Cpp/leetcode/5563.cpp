#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long sum_n(long a_1, long a_n, long n){
        if (a_n > a_1)
            return 0;
        return (a_1 + a_n) * n / 2;
    }
    static bool cmp(const int & a, const int & b){
        return a > b;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), cmp);
        long total_value = 0;
        int n = inventory.size();
        while (orders != 0){
            int i;
            for (i = 0; i < n-1 && inventory[i] == inventory[i+1]; i++);
            int sub = 0;
            if (i != n-1){
                sub = inventory[i] - inventory[i+1];
                if (sub >= orders){
                    long value = sum_n(inventory[i], inventory[i+1]+1, sub);
                    total_value += value;
                    total_value %= int(1e9+7);
                    orders -= sub;
                    inventory[i] = inventory[i+1];
                }
                else {
                    long value = sum_n(inventory[i], inventory[i]-orders+1, sub);
                    total_value += value;
                    total_value %= int(1e9+7);
                    return total_value;
                }
            }else {
                sub = inventory[i];
                if (sub >= orders){
                    long value = sum_n(inventory[i], 1, sub);
                    total_value += value;
                    total_value %= int(1e9+7);
                    orders -= sub;
                    inventory[i] = 0;
                }
                else {
                    long value = sum_n(inventory[i], inventory[i]-orders+1, sub);
                    total_value += value;
                    total_value %= int(1e9+7);
                    return total_value;
                }
            }
        }
        total_value %= int(1e9+7);
        return total_value;
    }
};
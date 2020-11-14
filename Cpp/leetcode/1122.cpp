#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for (int i = 0; i < arr2.size(); i++){
            mp[arr2[i]] = -arr2.size() + i;
        }
        sort(arr1.begin(), arr1.end(), [&](int a1,int a2){
            if (mp[a1] || mp[a2]){
                return mp[a1] < mp[a2];
            }
            return a1 < a2;
        });
        return arr1;
    }
};

int main(){
    Solution s;
    vector<int> arr1{2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2{2,1,4,3,9,6};
    s.relativeSortArray(arr1, arr2);
}
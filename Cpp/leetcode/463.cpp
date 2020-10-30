#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (j == 0 && grid[i][j] == 1)
                    ++ans;
                else if (j > 0 && grid[i][j-1] != grid[i][j])
                    ++ans;
                if (j == n-1 && grid[i][j] == 1)
                    ++ans;
            }
        }
        for (int j = 0; j < n; j++){
            for (int i = 0; i < m; i++){
                if (i == 0 && grid[i][j] == 1)
                    ++ans;
                else if (i > 0 && grid[i][j] != grid[i-1][j])
                    ++ans;
                if (i == m-1 && grid[i][j] == 1)
                    ++ans;
            }
        }
        return ans;
    }
};
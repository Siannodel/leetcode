#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        vector<vector<int>> dp(h, vector<int>(w, 0));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + grid[i][j];
                }
            }
        }
        return dp[h-1][w-1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1}};
    sol.maxValue(grid);
    return 0;
}
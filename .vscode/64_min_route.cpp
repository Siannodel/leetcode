#include<vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) return 0;
        int w = grid[0].size();
        vector<vector<int>> dp(h, vector<int>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if (i == 0) dp[i][j] = dp[i][j-1] + grid[i][j];
                else if (j == 0) dp[i][j] = dp[i-1][j] + grid[i][j];
                else dp[i][j] = min(dp[i][j-1] + grid[i][j], dp[i-1][j] + grid[i][j]);
            }
        }
        return dp[h-1][w-1];
    }
};
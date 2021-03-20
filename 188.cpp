#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxProfit2(vector<int>& prices)
    {
        int n = prices.size();
        if (n <= 1) return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            int tmp = prices[i] - prices[i-1];
            if (tmp > 0)
            {
                profit += tmp;
            }
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        if (k > n / 2)
        {
            return maxProfit2(prices);
        }
        else
        {
            vector<vector<int>> dp(n, vector<int>(2*k+1, 0));
            dp[0][0] = 0;
            dp[0][1] = -prices[0];
            for (int j = 2; j < 2*k+1; ++j)
            {
                dp[0][j] = -100000000;
            }
            for (int i = 1; i < n; ++i)
            {
                for (int j = 1; j < k + 1; ++j)
                {
                    dp[i][2*j-1] = max(dp[i][2*j-2] - prices[i], dp[i-1][2*j-1]);
                    dp[i][2*j] = max(dp[i][2*j-1] + prices[i], dp[i-1][2*j]);
                }
            }
            return dp[n-1][2*k];
        }
        
    }
};

int main()
{
    int k = 0;
    vector<int> prices = {1,3};
    Solution sol;
    sol.maxProfit(k, prices);
    return 0;
}
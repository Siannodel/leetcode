#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                int tmp = i - coins[j];
                if (tmp >= 0 && dp[tmp] != -1)
                {
                    if (dp[i] == -1 || dp[i] > dp[tmp] + 1)
                    {
                        dp[i] = dp[tmp] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main()
{
    Solution sol;
    vector<int> coins = {1,2,5};
    int amount = 11;
    int ans = sol.coinChange(coins, amount);
    cout << ans << endl;
    return 0;
}
#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:

    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        vector<int> flag(amount+1, 0);
        dp[0] = 1;
        for (int j = 0; j < coins.size(); ++j) 
        {
            for (int i = 1; i < dp.size(); ++i)
            {
                int tmp = i - coins[j];
                if (tmp >= 0)
                {
                    dp[i] += dp[tmp];
                    flag[i] = coins[j];
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
    int ans = sol.change(amount, coins);
    cout << ans << endl;
    return 0;
}
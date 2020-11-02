#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int max_len = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    tmp = max(tmp, dp[j]+1);
                    if (max_len < tmp)
                    {
                        max_len = tmp;
                        ans = 1;
                    }
                    else (max_len == tmp)
                    {
                        ++ans;
                    }
                }
            }
            dp[i] == tmp;
        }

        return ans;
    }
};
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_l = s.size();
        int p_l = p.size();
        vector<vector<int>> dp(s_l+1, vector<int>(p_l+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= s_l; i++)
        {
            for (int j = 1; j <= p_l; j++)
            {
                if (p[j-1] != '*')
                {
                    if (i > 0 && (p[j-1] == '.' || p[j-1] == s[i-1]))
                    {
                        dp[i][j] |= dp[i-1][j-1];
                    }
                }
                else
                {
                    dp[i][j] |= dp[i][j-2];
                    if (i>0 && (p[j-2] == '.' || p[j-2] == s[i-1]))
                    {
                        dp[i][j] |= dp[i-1][j];
                    }
                }
            }
        }
        return dp[s_l][p_l];
    }
};

int main()
{
    string s = "aa";
    string p = "a*";
    Solution sol;
    sol.isMatch(s, p);
}
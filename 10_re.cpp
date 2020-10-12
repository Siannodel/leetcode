#include <vector>
#include <iostream>
#include <string>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s;
        p = " " + p;
        int m = s.size();
        int n = p.size();
        bool dp[m+1][n+1];
        memset(dp,false,(m+1)*(n+1));
        dp[0][0] = true;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    if(s[i-1]!=p[j-2] && p[j-2]!='.')
                    {
                        dp[i][j] = dp[i][j-2];
                    }
                    else
                    {
                        //这个地方
                        dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                    }
                    
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution solution;
    string s = "aabef";
    string p = ".*";
    cout << solution.isMatch(s, p) << endl;

    system("pause");
    return 0;
}
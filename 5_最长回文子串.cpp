#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution1 {
public:
    //动态规划
    string longestPalindrome1(string s) {
        int n = s.size();
        vector< vector<int> > dp(n, vector<int>(n));
        string ans;
        //按长度遍历子串
        for (int l = 0; l < n; ++l)
        {
            for (int i = 0; i + l < n; ++i)
            {
                int j = i + l;
                if (l == 0)
                {
                    dp[i][j] = 1;
                }
                else if (l == 1)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if (dp[i][j] && l + 1 > ans.size())
                {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
    //中心扩展
    string longestPalindrome2(string s) {
        int n = s.size();
        int ans_start = 0;
        int ans_end = 0;
        for (int i = 0; i < n; i++)
        {
            int start = i;
            int end = i;
            while(start - 1 >= 0 && end + 1< n && s[start-1] == s[end+1])
            {
                --start;
                ++end;
            } 
            if (end - start > ans_end - ans_start)
            {
                ans_end = end;
                ans_start = start;
            }

            if (s[i] != s[i+1]) continue;

            start = i;
            end = i + 1;

            while(start - 1 >= 0 && end + 1< n && s[start-1] == s[end+1])
            {
                --start;
                ++end;
            } 
            if (end - start > ans_end - ans_start)
            {
                ans_end = end;
                ans_start = start;
            }
        }
        return s.substr(ans_start, ans_end - ans_start + 1);
    }
};


int main(){
    Solution1 s;
    
    system("pause");
    return 0;
}
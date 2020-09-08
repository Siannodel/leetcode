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

//又遇到这个题了 自己再写一遍
class Solution2 {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        if (s.size() == 1) return s;
        int max_l = 1;
        int start = 0;
        //int end = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            int p1 = i-1;
            int p2 = i+1;
            while(p1 >= 0 && p2 < s.size() && s[p1]==s[p2])
            {
                if (p2 - p1 + 1 > max_l)
                {
                    max_l = p2 - p1 + 1;
                    start = p1;
                    //end = p2;
                }
                --p1;
                ++p2; 
            }
            p1 = i;
            p2 = i+1;
            while(p1 >= 0 && p2 < s.size() && s[p1]==s[p2])
            {
                if (p2 - p1 + 1 > max_l)
                {
                    max_l = p2 - p1 + 1;
                    start = p1;
                    //end = p2;
                }
                --p1;
                ++p2; 
            }
        }
        return s.substr(start, max_l);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        vector< vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        string ans;
        int max_l = 0;
        for (int l = 1; l <= s.size(); ++l)
        {
            for(int i = 0; i < s.size() - l + 1; ++i)
            {
                int j = i + l - 1;
                if (l == 1)
                {
                    dp[i][j] = 1;
                }
                else if (l == 2)
                {
                    dp[i][j] = (s[i]==s[j]);
                }
                else
                {
                    dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
                }
                if (dp[i][j] && max_l < l)
                {
                    max_l = l;
                    ans = s.substr(i, l);
                }
            }
            return ans;
        }

    }
};
int main(){
    Solution1 s;
    
    system("pause");
    return 0;
}
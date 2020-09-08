#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    void helper(vector<string> &ans, string &s, int l_n, int r_n)
    {
        if (l_n == 0 && r_n == 0)
        {
            ans.push_back(s);
            return;
        }

        if (l_n > 0)
        {
            s.push_back('(');
            helper(ans, s, l_n-1, r_n+1);
            s.pop_back();
        }
        if (r_n > 0)
        {
            s.push_back(')');
            helper(ans, s, l_n, r_n-1);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        helper(ans, s, n, 0);
        return ans;
    }
};
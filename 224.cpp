#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isdigit(char c)
    {
        if (c >= '0' && c <= '9')
        {
            return true;
        }
        return false;
    }
    int helper(deque<char> &q)
    {
        stack<int> stk;
        int num = 0;
        char sign = '+';
        while(!q.empty())
        {
            char c = q.front();
            q.pop_front();
            if (isdigit(c))
                num = 10 * num + (c - '0');
            
            if (c == '(')
            {
                num = helper(q);
            }

            if ((!isdigit(c) && c != ' ') || q.empty())
            {
                if (sign == '+')
                {
                    stk.push(num);
                }
                else if (sign == '-')
                {
                    stk.push(-num);
                }
                else if (sign == '*')
                {
                    int pre = stk.top();
                    stk.pop();
                    stk.push(pre*num);
                }
                else if (sign == '/')
                {
                    int pre = stk.top();
                    stk.pop();
                    stk.push(pre/num);
                }
                sign = c;
                num = 0;
            }

            if (c == ')')
            {
                break;
            }
        }
        int res = 0;
        while(!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
    int calculate(string s) {
        deque<char> q(s.begin(), s.end());
        int ans = helper(q);
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "(1+(4+5+2)-3)+(6+8)";
    sol.calculate(s);
    return 0;
}
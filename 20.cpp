#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;

        stack<char> stk;
        for (auto c : s)
        {
            if (pairs.count(c))
            {
                if (!stk.empty() && stk.top() == pairs[c])
                    stk.pop();
                else
                {
                    return false;
                }
                
            }
            else
            {
                stk.push(c);
            }
            
        }

        return stk.empty();
    }

    unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
};
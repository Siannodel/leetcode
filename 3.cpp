#include <string>
#include <unordered_set>
#include <math.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> set;
        
        int start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (set.count(s[i]) == 0)
            {
                set.insert(s[i]);
                ans = max(ans, i - start);
            }
            else
            {
                while(!set.empty())
                {
                    set.erase(s[start]);
                    ++start;
                    if(set.count(s[i]) == 0)
                    {
                        set.insert(s[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
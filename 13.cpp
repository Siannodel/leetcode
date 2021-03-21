#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    Solution()
    {
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
    }

    int romanToInt(string s) {
        int res = 0;
        int pre_n = 1000;
        for(auto c : s)
        {
            res += dict[c];
            if (pre_n < dict[c])
            {
                res -= 2 * pre_n;
            }
            pre_n = dict[c];
        }
        return res;
    }

    unordered_map<char, int> dict;
};
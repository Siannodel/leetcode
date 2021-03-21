#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int i = 0;
        while(true)
        {
            if (i >= strs[0].size()) return prefix;
            char c = strs[0][i];
            for (auto& s : strs)
            {
                if (i >= s.size() || s[i] != c)
                    return prefix;
            }
            prefix.push_back(c);
        }
    }
};
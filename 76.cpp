#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> needs;
        unordered_map<char, int> counter;
        for (auto c : t)
        {
            needs[c]++;
        }
        int start = 0;
        int minlen = INT_MAX;

        int left = 0;
        int right = 0;
        int match = 0;
        while(right < s.size())
        {
            auto c = s[right];
            counter[c]++;
            if (needs.count(c) && counter[c] == needs[c])
            {
                ++match;
            }

            while (match == needs.size())
            {
                if (minlen > right - left + 1)
                {
                    start = left;
                    minlen = right - left + 1;
                }

                auto c2 = s[left];
                counter[c2]--;
                if (needs.count(c2) && counter[c2] < needs[c2])
                {
                    --match;
                }
                ++left;
            }
            ++right;
        }
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};

int main()
{
    Solution sol;
    string s = "ab";
    string t = "a";
    string ans = sol.minWindow(s, t);
    return 0;
}
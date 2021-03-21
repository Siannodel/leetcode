#include <vector>
#include <utility>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int i = 0;
        while(num > 0)
        {
            if (num > dict[i].first)
            {
                ans += dict[i].second;
                num -= dict[i].first;
            }
            else
            {
                ++i;
            }
            
        }
        return ans;
    }
    vector<pair<int, string> > dict = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};
};
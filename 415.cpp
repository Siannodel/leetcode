#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string ans = "";
        int carry = 0;
        int l = max(num1.size(), num2.size());
        for (int i = 0; i < l; ++i)
        {
            if (i < num1.size())
            {
                carry += num1[i] - '0';
            }
            if (i < num2.size())
            {
                carry += num2[i] - '0';
            }
            ans.push_back('0' + carry%10);
            carry /= 10;
        }
        if (carry > 0)
        {
            ans.push_back('0' + carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
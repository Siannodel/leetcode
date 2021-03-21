#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows, "");
        int i = 0;
        bool flag = true;
        for (auto c : s)
        {
            rows[i].push_back(c);
            i += flag ? 1 : -1;
            if (i == 0 || i == numRows-1)
            {
                flag = !flag;
            }
        }
        string ans;
        for (auto row : rows)
        {
            ans += row;
        }
        return ans;
	}
};

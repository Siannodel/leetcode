// 6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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

		vector<string> rows(min(numRows, int(s.size())));
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) ret += row;
		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}


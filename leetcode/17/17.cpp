// 17.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<string> dict = {
		"", "", "abc", "def", "ghi", "jkl", "mno",
		"pqrs", "tuv", "wxyz"
	};

	void helper(vector<string> &ans, string &cur_str, string &digits, int n)
	{
		if (n == digits.size())
		{
			ans.push_back(cur_str);
			return;
		}
		int digit = digits[n] - '0';
		for (int i = 0; i < dict[digit].size(); ++i)
		{
			cur_str.push_back(dict[digit][i]);
			helper(ans, cur_str, digits, n + 1);
			cur_str.pop_back();
		}
		return;
	}
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		if (digits == "") return ans;
		string cur_str = "";
		helper(ans, cur_str, digits, 0);
		return ans;
	}
};

int main()
{
	Solution s;
	s.letterCombinations("23");
    return 0;
}


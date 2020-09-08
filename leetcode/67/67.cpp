// 67.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	char helper(char c1, char c2, bool& carry)
	{
		char res;
		bool new_carry = false;
		if (c1 == '0' && c2 == '0')
			res = '0';
		else if (c1 == '1' && c2 == '1')
		{
			res = '0';
			new_carry = true;
		}
		else
			res = '1';

		if (carry)
		{
			if (res == '0')
				res = '1';
			else
			{
				res = '0';
				new_carry = true;
			}

		}
		carry = new_carry;
		return res;
	}
	string addBinary(string a, string b) {
		if (b.size() > a.size())
			swap(a, b);
		//a.size() >= b.size()
		string res(a.size() + 1, '0');
		int a_i = a.size() - 1;
		int b_i = b.size() - 1;
		int res_i = res.size() - 1;
		bool carry = false;
		while (b_i >= 0)
		{
			res[res_i] = helper(a[a_i], b[b_i], carry);
			--b_i;
			--a_i;
			--res_i;
		}
		if (carry)
		{
			res[res_i] = '1';
			carry = false;
		}

		while (a_i >= 0)
		{
			res[res_i] = helper(res[res_i], a[a_i], carry);
			--a_i;
			--res_i;
		}
		if (carry)
		{
			res[res_i] = '1';
			carry = false;
		}
		if (res[0] == '0')
			res = res.substr(1, res.size() - 1);
		return res;
	}
};

int main()
{	
	Solution s;
	string a = "11";
	string b = "1";
	string res = s.addBinary(a, b);
	cout << res << endl;
	system("pause");
    return 0;
}


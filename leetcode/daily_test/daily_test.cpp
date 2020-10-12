// daily_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

//十进制转二进制
bool  dec2bin(int n, vector<int> &ans)
{
	ans = vector<int>(16, 0);
	int count = 0;
	while (n)
	{
		ans[count] = n & 1;
		n >>= 1;
		++count;
		if (count >= 16)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<int> ans;
	dec2bin(16, ans);
	cout << 15 << endl;
	system("pause");
    return 0;
}


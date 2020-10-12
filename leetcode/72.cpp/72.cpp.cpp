// 72.cpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
	int minDistance(string word1, string word2) {
		if (word1.size() > word2.size())
			swap(word1, word2);

		int l1 = word1.size();
		int l2 = word2.size();
		vector<vector<int> > dp(l1 + 1, vector<int>(l2 + 1, 0));
		for (int i = 0; i < l1 + 1; ++i)
			dp[i][0] = i;
		for (int i = 0; i < l2 + 1; ++i)
			dp[0][i] = i;

		for (int i = 1; i < l1 + 1; ++i)
		{
			for (int j = 1; j < l2 + 1; ++j)
			{
				//dp[i][j] = min(dp[i - 1][j - 1], dp[i-1][j]);
				//dp[i][j] = min(dp[i][j - 1], dp[i][j]);
				if (word1[i - 1] != word2[j - 1])
				{
					dp[i][j] = min(dp[i - 1][j - 1]+1, dp[i - 1][j]+1);
					dp[i][j] = min(dp[i][j - 1]+1, dp[i][j]);
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]+1);
					dp[i][j] = min(dp[i][j - 1]+1, dp[i][j]);
				}

			}
		}
		return dp[l1][l2];
	}
};

class Solution {
public:
	int getSum(int a, int b) {
		while (b != 0)
		{
			int tmp = a ^ b;
			b = (a & b) << 1;
			a = tmp;
		}
		return a;
	}
};

int main()
{
	Solution sol;
	cout << sol.getSum(1, -1) << endl;
	system("pause");
    return 0;
}


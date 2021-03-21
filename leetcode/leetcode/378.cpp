#include "stdafx.h"
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
	struct T{
		int x;
		int y;
		int n;
		T(){}
		T(int _x, int _y, int _n)
		{
			x = _x;
			y = _y;
			n = _n;
		}
		//!!!
		//注意重载 < 符合的两个const 必须添加
		bool operator<(const T& other) const
		{
			return n > other.n;
		};
	};
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		
		int h = matrix.size();
		int w = matrix[0].size();
		vector<vector<bool>> visited(h, vector<bool>(w, false));
		priority_queue<T, vector<T>> pq;
		pq.emplace(0, 0, matrix[0][0]);
		visited[0][0] = true;
		int count = 1;
		while (!pq.empty())
		{
			auto t = pq.top();
			pq.pop();
			cout << count << ":(" << t.x << "," << t.y << "," << t.n << ")" << endl;
			if (count == k)
				return t.n;
			++count;
			if (t.x + 1 < w && visited[t.y][t.x + 1] == false)
			{
				pq.emplace(t.x + 1, t.y, matrix[t.y][t.x + 1]);
				visited[t.y][t.x + 1] = true;
			}
			if (t.y + 1 < h && visited[t.y + 1][t.x] == false)
			{
				pq.emplace(t.x, t.y + 1, matrix[t.y + 1][t.x]);
				visited[t.y + 1][t.x] = true;
			}
		}
		return 0;
	}
};
class Solution2 {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int, vector<int>, less<int> > pq;
		int h = matrix.size();
		int w = matrix[0].size();
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (pq.size() < k)
				{
					pq.push(matrix[i][j]);
				}
				else
				{
					if (matrix[i][j] >= pq.top())
					{
						break;
					}
					else
					{
						pq.pop();
						pq.push(matrix[i][j]);
					}
				}
			}
		}
		return pq.top();
	}
};
class Solution3 {
public:
	//寻找在matrix中有多少个<=n的数
	int func(vector<vector<int>>& matrix, int n) {
		int h = matrix.size();
		int w = matrix[0].size();
		int x = 0;
		int y = h - 1;
		int count = 0;
		while (x < w && y >= 0)
		{
			if (matrix[y][x] <= n)
			{
				count += y + 1;
				++x;
			}
			else
			{
				--y;
			}
		}
		return count;
	}

	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int h = matrix.size();
		int w = matrix[0].size();
		
		int left = matrix[0][0];
		int right = matrix[h - 1][w - 1];
		
		while (left < right)
		{
			int mid = (right + left) / 2;
			int count = func(matrix, mid);
			if (count < k)
			{
				left = mid + 1;  
			}
			else
			{
				right = mid;
			}
		}

		return left;
	}
};
int main1()
{
	vector<vector<int> > matrix = {
		{1, 5, 9}, 
		{10, 11, 13}, 
		{12, 13, 15}
	};
	int k = 8;
	Solution3 s;
	int result = s.kthSmallest(matrix, k);
	cout << result << endl;
	system("pause");
	return 0;
}
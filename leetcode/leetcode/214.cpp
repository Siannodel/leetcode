// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int> > pq;
		for (int i = 0; i < nums.size(); ++i)
		{
			pq.push(nums[i]);
			if (pq.size() > k)
			{
				pq.pop();
			}
		}
		return pq.top();
	}
};

class Solution2 {
public:

	int partition(vector<int>& nums, int left, int right)
	{
		int i = left;
		int j = right;
		int pivot = nums[left];
		while (i < j)
		{
			while (i < j && nums[--j] < pivot) {}
			nums[i] = nums[j];
			while (i < j && nums[++i] > pivot) {}
			nums[j] = nums[i];
		}
		nums[i] = pivot;
		return i;
	}

	int findKthLargest(vector<int>& nums, int k) {
		int i = 0;
		int j = nums.size();
		while (true)
		{
			int x = partition(nums, i, j);
			if (x == k-1)
				break;
			else if (x > k-1)
			{
				j = x;
			}
			else
			{
				i = x + 1;
			}

		}
		return nums[k-1];
	}
};

int main1()
{
	Solution2 s;
	vector<int> nums = { 3,2,1,2,4,5,5,6};
	int k = 4;
	int r = s.findKthLargest(nums, k);
	cout << r << endl;
	system("pause");
	return 0;
}


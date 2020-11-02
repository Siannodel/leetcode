// daily_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100005

using namespace std;
typedef long long ll;

class Solution2 
{
public:
	class Node 
	{
	public:
		int m, c;
		Node() : m(0), c(0) {}
		Node& operator += (Node& b) 
		{
			if (b.m > m)
			{
				m = b.m;
				c = b.c;
			}
			else if (b.m == m)
			{
				c += b.c;
			}
			return *this;
		}
	};

	void add(Node nodes[], int rk, Node &val, int N)
	{
		for (; rk <= N; rk += (rk &(-rk)))
		{
			nodes[rk] += val;
		}
	}

	Node query(Node nodes[], int rk)
	{
		Node res;
		for (; rk; rk -= (rk & (-rk)))
		{
			res += nodes[rk];
		}
		return res;
	}

	int findNumberOfLIS(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> numsort(nums.begin(), nums.end());
		sort(numsort.begin(), numsort.end());
		Node nodes[nums.size() + 1] = { Node() };
		Node res = Node();

		for (int i : nums)
		{
			//当前数字的排名
			int rk = lower_bound(numsort.begin(), numsort.end(), i) - numsort.begin();
			//求出当前尾数的 最长序列长度 和 个数
			Node cur = query(nodes, rk);
			cur.m++, cur.c = max(cur.c, 1);
		}
	}
};

class Solution
{
public:

	class Value
	{
	public:
		Value() {}
		Value(int len, int ct)
		{
			length = len;
			count = ct;
		}

		int length;
		int count;
	};
	class Node
	{
	public:
		Node(int start, int end)
		{
			range_left = start;
			range_right = end;
			left = NULL;
			right = NULL;
			val = Value(0, 1);
		}

		int get_range_mid()
		{
			return range_left + (range_right - range_left) / 2;
		}

		Node* get_left()
		{
			if (left == NULL)
				left = new Node(range_left, get_range_mid());
			return left;
		}

		Node* get_right()
		{
			if (right == NULL)
				right = new Node(get_range_mid() + 1, range_right);
			return right;
		}

	public:
		int range_left, range_right;
		Node *left, *right;
		Value val;
	};

	Value merge(Value v1, Value v2)
	{
		if (v1.length == v2.length)
		{
			if (v1.length == 0)
				return Value(0, 1);
			return Value(v1.length, v1.count + v2.count);
		}
		return v1.length > v2.length ? v1 : v2;
	}

	void insert(Node *node, int key, Value val)
	{
		//如果是叶子节点，则直接累加
		//注意这里是使用merge，因为可能原本有值
		if (node->range_left == node->range_right)
		{
			node->val = merge(val, node->val);
		}
		else if (key <= node->get_range_mid())
		{
			insert(node->get_left(), key, val);
		}
		else
		{
			insert(node->get_right(), key, val);
		}
		node->val = merge(node->get_left()->val, node->get_right()->val);
	}

	Value query(Node *node, int key)
	{
		if (node->range_right <= key)
			return node->val;
		else if (node->range_left > key)
			return Value(0, 1);
		else
			return merge(query(node->get_left(), key), query(node->get_right(), key));
	}

	int findNumberOfLIS(vector<int>& nums)
	{
		if (nums.size() == 0) return 0;
		int min_n = nums[0];
		int max_n = nums[0];
		for (int n : nums)
		{
			min_n = min(min_n, n);
			max_n = max(max_n, n);
		}
		Node *root = new Node(min_n, max_n);
		for (int n : nums)
		{
			Value v = query(root, n - 1);
			insert(root, n, Value(v.length + 1, v.count));
		}
		return root->val.count;
	}
};


int main()
{
	Solution sol;
	vector<int> v = { 10, 9, 2, 5, 3, 7, 101, 18 };
	int ans = sol.findNumberOfLIS(v);
	cout << ans << endl;
	system("pause");
    return 0;
}


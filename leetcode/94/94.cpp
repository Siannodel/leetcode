// 94.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> result;
		stack<TreeNode*> s;
		auto p = root;
		while (p || !s.empty())
		{
			while (p)
			{
				result.push_back(p->val);
				s.push(p->right);
				p = p->left;
			}
			p = s.top();
			s.pop();
		}
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> s;
		auto p = root;
		while (p || !s.empty())
		{
			while (p)
			{
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			result.push_back(p->val);
			p = p->right;
		}
		return result;
	}

};
int main()
{
    return 0;
}


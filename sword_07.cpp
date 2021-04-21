#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(n), right(NULL) {}
};

class Solution
{
public:
    unordered_map<int, int> m;

    TreeNode *func(vector<int> &preorder, vector<int> &inorder, int begin1, int begin2, int len)
    {
        //cout << begin1 << " , "  << begin2 << " , " << len << endl;
        if (len <= 0)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[begin1]);
        int head_index = m[preorder[begin1]];
        //cout << head_index << endl;
        int l_len = head_index - begin2;
        int r_len = len - (head_index - begin2) - 1;
        node->left = func(preorder, inorder, begin1 + 1, begin2, l_len);
        node->right = func(preorder, inorder, begin1 + l_len + 1, head_index + 1, r_len);
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        return func(preorder, inorder, 0, 0, preorder.size());
    }
};
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* func(vector<int>& nums, int left, int right)
    {
        if (left > right) return NULL;

        int max_index = left;
        int max_value = -1;
        for (int i = left; i <= right; ++i)
        {
            if (nums[i] > max_value)
            {
                max_index = i;
                max_value = nums[i];
            }
        }
        TreeNode* node = new TreeNode(max_value);
        node->left = func(nums, left, max_index-1);
        node->right = func(nums, max_index+1, right);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return func(nums, 0, nums.size()-1);
    }
};
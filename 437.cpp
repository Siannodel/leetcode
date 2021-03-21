
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int helper(TreeNode* root, int sum)
    {
        if (root == nullptr) return 0;
        int count1 = root->val == sum ? 1 : 0;
        int count2 = helper(root->left, sum - root->val);
        int count3 = helper(root->right, sum - root->val);
        return count1 + count2 + count3;
    }
    int pathSum(TreeNode* root, int sum) 
    {
        if (root == nullptr)
            return 0;
        int count1 = helper(root, sum);
        int count2 = pathSum(root->left, sum);
        int count3 = pathSum(root->right, sum);
        return count1 + count2 + count3;
    }
};
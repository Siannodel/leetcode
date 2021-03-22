class Solution {
public:
    bool isValidBST2(TreeNode* root, TreeNode* min_node, TreeNode* max_node)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (min_node != nullptr && root->val <= min_node->val)
        {
            return false;
        }
        if (max_node != nullptr && root->val >= max_node->val)
        {
            return false;
        }
        return isValidBST2(root->left, min_node, root) && isValidBST2(root->right, root, max_node);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST2(root, nullptr, nullptr);
    }
};
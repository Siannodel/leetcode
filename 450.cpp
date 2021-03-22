class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {
            if (root->right == nullptr && root->left == nullptr)
                return nullptr;
            else if (root->right == nullptr)
                return root->left;
            else if (root->left == nullptr)
                return root->right;
            else
            {
                TreeNode* tmp = root->right;
                while(tmp->left != nullptr)
                {
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
            }
        }
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};
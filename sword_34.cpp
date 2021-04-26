class Solution {
public:
    void func(TreeNode* root, int target, vector<vector<int>>& res, vector<int>& cur)
    {
        if (root == nullptr)
        {
            return;
        }
        cur.push_back(root->val);
        int new_target = target - root->val;
        
        if (root->left == nullptr && root->right == nullptr && new_target == 0)
        {
            res.push_back(cur);
        }
        
        func(root->left, new_target, res, cur);
        func(root->right, new_target, res, cur);
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        func(root, target, res, cur);
        return res;
    }
};
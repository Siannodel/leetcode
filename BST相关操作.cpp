struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//判断搜索树是否合法
bool isValidBST2(TreeNode *root, TreeNode *min_node, TreeNode *max_node)
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
bool isValidBST(TreeNode *root)
{
    return isValidBST2(root, nullptr, nullptr);
}

//在 BST 中查找一个数是否存在
bool isInBST(TreeNode *root, int target)
{
    if (root == nullptr)
        return false;
    if (root->val == target)
        return true;
    if (root->val < target)
        return isInBST(root->left, target);
    if (root->val > target)
        return isInBST(root->right, target);
}
// 插入
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);
    if (root->val == val)
        return root;
    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    if (root->val < val)
        root->left = insertIntoBST(root->left, val);
    return root;
}
//删除
TreeNode *deleteNode(TreeNode *root, int key)
{
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
            TreeNode *tmp = root->right;
            while (tmp->left != nullptr)
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
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* func(vector<int>& preorder, int l1, int r1,
        vector<int>& inorder, int l2, int r2)
    {
        if (l1 > r1) return nullptr;
        TreeNode* node = new TreeNode(preorder[l1]);
        int index = l2;
        for (int i = l2; i <= r2; ++i)
        {
            if (inorder[i] == preorder[l1])
            {
                index = i;
                break;
            }
        }
        int length = index - l2;

        node->left = func(preorder, l1 + 1, l1 + length,
            inorder, l2, index-1);
        node->right = func(preorder, l1 + length + 1, r1,
            inorder, index+1, r2);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return func(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
#include <stack>

using namespace std;

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
    void flatten2(TreeNode* root) {
        if (root == nullptr) return;
        stack<TreeNode*> s;
        TreeNode* cur_node = root;
        TreeNode* pre_node;
        while(cur_node || !s.empty())
        {
            while(cur_node)
            {
                if (cur_node->right) s.push(cur_node->right);
                cur_node->right = cur_node->left;
                cur_node->left = nullptr;
                pre_node = cur_node;
                cur_node = cur_node->right;
            }
            if (s.empty()) break;
            TreeNode* tmp = s.top();
            s.pop();
            pre_node->right = tmp;
            cur_node = tmp;
        }
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode* curr = root;

        while(curr)
        {
            if(curr->left)
            {
                TreeNode* pre = curr->left;
                while(pre->right)
                {
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
        return;
    }
};
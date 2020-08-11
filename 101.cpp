#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (!root->left || !root->right) return false;
        queue<TreeNode*> lq;
        queue<TreeNode*> rq;
        lq.push(root->left);
        rq.push(root->right);
        while (!lq.empty() && !rq.empty())
        {
            TreeNode* l = lq.front(); lq.pop();
            TreeNode* r = rq.front(); rq.pop();
            if (l->val != r->val) return false;
            if (l->left && r->right)
            {
                lq.push(l->left);
                rq.push(r->right);
            }
            else if (l->left || r->right)
            {
                return false;
            }
            if (l->right && r->left)
            {
                lq.push(l->right);
                rq.push(r->left);
            }
            else if (l->right || r->left)
            {
                return false;
            }

        }
        if (!lq.empty() || !rq.empty()) return false;
        return true;
    }
};
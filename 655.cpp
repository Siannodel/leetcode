#include <vector>
#include <string>
#include <math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int deep(TreeNode* root)
    {
        if (root == nullptr) return 0;
        return max(deep(root->left), deep(root->right)) + 1;
    }
    void func(vector<vector<string>> &v, TreeNode* root, int d, int left, int right)
    {
        if (root == nullptr) return;
        int mid = (left+right)/2;
        v[d][mid] = to_string(root->val);
        func(v, root->left, d+1, left, mid-1);
        func(v, root->right, d+1, mid+1, right);
    }
    vector<vector<string>> printTree(TreeNode* root) 
    {
        int m = deep(root);
        int n = pow(2, m) - 1;
        vector<vector<string> > result(m, vector<string> (n));
        func(result, root, 0, 0, n-1);
        return result;
    }
};
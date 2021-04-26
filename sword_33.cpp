class Solution {
public:
    bool func(vector<int>& postorder, int l, int r)
    {
        if (l >= r-1) return true;
        int n = postorder[r];
        int index = l-1;
        bool flag = true;
        for (int i = l; i <= r-1; i++)
        {
            if (postorder[i] < n)
            {
                if (!flag) return false; 
                index = i;
            }
            else
            {
                flag = false;
            }
        }
        return func(postorder, l, index) && func(postorder, index+1, r-1);

    }
    bool verifyPostorder(vector<int>& postorder) {
        return func(postorder, 0, postorder.size()-1);
    }
};
class Solution {
public:
    int m_n;
    //int m_k;
    void func(vector<vector<int>>& res, vector<int>& curr, int a, int b)
    {
        if (b == 0)
        {
            res.push_back(curr);
            return;
        }
        if (m_n - a + 1 < b)
        {
            return;
        }
        for (int i = a; i <= m_n; ++i)
        {
            curr.push_back(i);
            func(res, curr, i + 1, b - 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        m_n = n;
        //m_k = k;
        vector<vector<int>> res;
        vector<int> curr;
        func(res, curr, 1, k);
        return res;
    }
};
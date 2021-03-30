class Solution {
public:
    void func(const vector<int>& nums, vector<vector<int>>& res, vector<int>& v, int i)
    {
        if (i == nums.size())
        {
            res.push_back(v);
            return;
        }
        func(nums, res, v, i+1);
        v.push_back(nums[i]);
        func(nums, res, v, i+1);
        v.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        func(nums, res, v, 0);
        return res;
    }
};
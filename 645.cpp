class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans (2, -1);
        for(int i = 0; i< nums.size(); ++i)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
                ans[0] = index + 1;
            else
                nums[index] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};
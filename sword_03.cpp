class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            while(nums[i] != i)
            {
                int j = nums[i];
                if (j == nums[j])
                {
                    return j;
                }
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        return -1;
    }
};
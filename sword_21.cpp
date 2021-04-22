#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        int l = 0;
        int r = nums.size()-1;

        while(l < r)
        {
            if ((nums[l]&1) == 1)
            {
                l++;
                continue;
            }
            if ((nums[r]&1) == 0)
            {
                r--;
                continue;
            }
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
        }
        return nums;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4};
    Solution sol;
    sol.exchange(nums);
}
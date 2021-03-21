#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int flag = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] >= flag)
            {
                if (flag <= target && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
                
            }
            else
            {
                if (flag > target && target > nums[mid])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
                
            }
            
        }
        return -1;
    }
};
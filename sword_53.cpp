#include <vector>
using namespace std;

class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        int start = 0;

        int l = 0;
        int r = len-1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if (nums[mid] < target)
            {
                l = mid+1;
            }
            else if (nums[mid] > target)
            {
                r = mid-1;
            }
            else if (nums[mid] == target)
            {
                r = mid -1;
            }
        }
        if (nums[l] != target)
        {
            return 0;
        }
        start = l;
        r = len - 1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if (nums[mid] < target)
            {
                l = mid+1;
            }
            else if (nums[mid] > target)
            {
                r = mid-1;
            }
            else if (nums[mid] == target)
            {
                l = mid+1;
            }
        }
        return r - start + 1;
    }
};

int main()
{
    vector<int> nums = {2,2};
    int target = 3;
    Solution sol;
    sol.search(nums, target);
}
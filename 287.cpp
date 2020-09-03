#include <vector>

using namespace std;


class Solution {
public:
    int count(vector<int>& nums, int x)
    {
        int c = 0;
        for (auto n : nums)
        {
            if (n <= x) ++c;
        }
        return c;
    }
    int findDuplicate(vector<int>& nums) 
    {

        int left = 1;
        int right = nums.size() - 1;

        while(true)
        {
            int mid = (left + right) / 2;
            int c = count(nums, mid);
            if (c <= mid) left = mid + 1;
            else right = mid - 1;
            if (left > right)
            {
                return left;
            }
        }
    }
};

class Solution1 {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size() - 1;
        int t = 1;
        int x = 0;
        int y = 0;
        int result = 0;
        while(n >= t)
        {
            for(auto &num : nums)
            {
                if (num & t) ++x;
            }
            for (int i = 1; i <= n; ++i)
            {
                if (i & t) ++y;
            }
            if (x > y) result += t;
            t *= 2;
            x = 0;
            y = 0;
        }
        return result;
    }
};

class Solution2 {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow = 0;
        int fast = 0;

        while(slow < nums.size() && fast <= nums.size())
        {
            slow = nums[slow];
            fast = nums[fast];
            if (fast < nums.size())
                fast = nums[fast];
            if (slow == fast) break;
        }
        slow = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
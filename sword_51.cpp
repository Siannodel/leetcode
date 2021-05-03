#include <vector>

using namespace std;

class Solution {
public:
    int func(vector<int>& nums, int l, int r)
    {
        if (l >=r) return 0;
        int count = 0;
        int mid = l + (r-l)/2;
        count += func(nums, l, mid);
        count += func(nums, mid+1, r);
        int i = l;
        int j = mid+1;
        vector<int> v;
        while(i <= mid && j <= r)
        {
            if (nums[i] > nums[j])
            {
                v.push_back(nums[j]);
                count += mid - i + 1;
                j++;
            }
            else
            {
                v.push_back(nums[i]);
                i++;
            }
        }
        while(i <= mid)
        {
            v.push_back(nums[i]);
            i++;
        }
        while(j <= r)
        {
            v.push_back(nums[j]);
            j++;
        }
        for(int i = l; i <= r; i++)
        {
            nums[i] = v[i-l];
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        return func(nums, 0, nums.size()-1);
    }
};

int main()
{
    vector<int> nums = {7,5,6,4};
    Solution sol;
    int res = sol.reversePairs(nums);
    return 0;
}
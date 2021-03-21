#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Solution1
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0) return 0;
        int ans = nums[0];
        int current = 0;
        for (const auto &num : nums)
        {
            current = max(current + num, num);
            ans = max(ans, current);
        }
        return ans;
    }
};
class Solution
{
public:
    struct Status
    {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r)
    {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    }

    Status get(vector<int> &a, int l, int r)
    {
        if (l == r) return (Status) {a[l], a[l], a[l], a[l]};
        int m = (l+r)/2;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m+1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int> &nums)
    {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};


    system("pause");
    return 0;
}
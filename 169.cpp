#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        for (auto n : nums)
        {
            if (count == 0)
            {
                ans = n;
            }
            if (ans == n)
            {
                ++count;
            }
            else
            {
                --count;
            }
            
        }
        return ans;
    }
};
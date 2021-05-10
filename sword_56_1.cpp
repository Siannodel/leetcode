#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        
        int a = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            a ^= nums[i];
        }
        int x = a^(a&(a-1));
        
        int b = 0;
        int c = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & x)
            {
                b ^= nums[i];
            }
            else
            {
                c ^= nums[i];
            }
        }
        return {b, c};
    }
};

int main() 
{
    vector<int> nums = {1,2,5,2};
    Solution sol;
    sol.singleNumbers(nums);
    return 0;
}
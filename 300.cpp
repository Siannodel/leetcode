#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> pre_nums;
        vector<int> lengths;

        for (auto num : nums)
        {
            int tmp_l = 1;
            for (int i = 0; i < pre_nums.size(); ++i)
            {
                if (pre_nums[i] < num)
                {
                    if (tmp_l < lengths[i] + 1)
                        tmp_l = lengths[i] + 1;
                }
            }
           
            pre_nums.push_back(num);
            lengths.push_back(tmp_l);
        }
        int max_l = 0;
        for (auto l : lengths)
        {
            if(l > max_l) max_l = l;
        }
        return max_l;
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> d;
        d.push_back(nums[0]);
        
        for(auto num : nums)
        {
            if (num > d[d.size()-1])
            {
                d.push_back(num);
            }
            else
            {
                //二分查找,寻找第一个大于等于num的位置
                int l = 0;
                int r = d.size() - 1;
                while(l < r)
                {
                    int mid = (l + r) >> 1;
                    if (d[mid] >= num)
                    {
                        r = mid; 
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                d[r] = num;      
            }   
        }
        return d.size();
    }
};

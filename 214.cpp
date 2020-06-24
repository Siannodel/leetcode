#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < nums.size(); ++i)
        {
            pq.push(nums[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};

class Solution2 {
public:
    
    int func(vector<int>& nums, int i, int j)
    {
        while(i != j)
        {
            while(nums[i] > nums[j])
                --j;
            swap(nums[i], nums[j]);

            while(nums[i] > nums[j])
                ++i;
            swap(nums[i], nums[j]);
        }
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int i = 0;
        int j = nums.size() - 1;
        while(true)
        {
            int x = func(nums, i, j);
            if (x == k) 
                break;
            else if (x > k)
            {
                j = x - 1;
            }
            else
            {
                i = x + 1;
            }
            
        }
        return nums[k];
    }
};

int main()
{
    Solution2 s;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    int r = s.findKthLargest(nums, k);
    cout << r << endl;
}
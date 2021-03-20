#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int partition(vector<pair<int, int>>& v, int left, int right)
    {
        int picked = rand() % (right - left + 1) + left;
        swap(v[picked], v[right]);
        int n = v[right].second;
        int i = left;
        int j = right;
        while(i < j)
        {
            while(v[i].second >= n)
            {
                i++;
            }
            while(v[j].second <= n)
            {
                j--;
            }
            if (i < j)
            {
                swap(v[i], v[j]);
            }
        }
        swap(v[i], v[right]);
        return i;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] += 1;
        }
        vector<pair<int,int>> v;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            v.push_back(*it);
        }

        int left = 0;
        int right = v.size() - 1;
        while(left < right)
        {
            int pivot = partition(v, left, right);
            if (pivot > k)
            {
                right = pivot - 1;
            }
            else if (pivot < k)
            {
                left = pivot + 1;
            }
            else
            {
                break;
            }
        }

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(v[i].first);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2};
    int k = 2;
    vector<int> res = s.topKFrequent(nums, 2);
    return 0;
}
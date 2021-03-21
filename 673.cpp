#include <vector>

using namespace std;

class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
		vector<int> lengths(nums.size(), 1);
		vector<int> counters(nums.size(), 1);

		for (int i = 0; i < nums.size(); ++i)
		{
			int tmp = 1;
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j])
				{
					if (lengths[j] + 1 > lengths[i])
					{
						lengths[i] = lengths[j] + 1;
						counters[i] = counters[j];
					}
					else if (lengths[j] + 1 == lengths[i])
					{
						counters[i] += counters[j];
					}

				}
			}
			
		}

		int max_len = *max_element(lengths.begin(), lengths.end());
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (lengths[i] == max_len)
			{
				ans += counters[i];
			}
		}

		return ans;
	}
};
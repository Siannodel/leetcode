#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int i1 = 0;
        int i2 = numbers.size() - 1;
        while(i2 > i1)
        {
            if (numbers[i1] + numbers[i2] == target) break;
            if (numbers[i1] + numbers[i2] > target) --i2;
            if (numbers[i1] + numbers[i2] < target) ++i1;
        }
        return {i1 + 1, i2 + 1};
    }
};
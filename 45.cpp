#include <vector>
#include <iostream>

using namespace std;

class Solution2 {
public:
    int jump(vector<int>& nums) {
        vector<int> tmp(nums.size(), -1);
        tmp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                if(i + j < tmp.size() && (tmp[i + j] == -1 || tmp[i] + 1 < tmp[i+j])){
                    tmp[i + j] = tmp[i] + 1;
                }
            }
        }

        for (int i = 0; i < tmp.size(); i++) {
            cout<< tmp[i] << " ";
        }
        return tmp[tmp.size()-1];
    }
};
//贪心算法，遍历数组 每次找到能够跳最远的地方，当需要跳的时候 步数加1，跳到最远的地方
class Solution {
public:
    int jump(vector<int> &nums) {
        int step = 0;
        for (int i=0, maxpos=0, curpos=0; i<nums.size(); ++i) {
            if (i>maxpos) return -1;
            if (i>curpos){
                curpos = maxpos;
                ++step;
            }
            maxpos = max(maxpos, i+nums[i]);
        }
        return step;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    s.jump(nums);
    system("pause");
    return 0;
}
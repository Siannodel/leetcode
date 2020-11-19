#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
        //初始化
        //当楼层为1时，不管有多少个鸡蛋，都只需1次实验
        for(int j = 1; j <= K; ++j)
        {
            dp[1][j] = 1;
        }
        //当只有一个鸡蛋时，只能进行线性搜索
        for(int i = 1; i <= N; ++i)
        {
            dp[i][1] = i;
        }
        for(int i = 2 ; i <= N ; ++i)
        {
            for(int j = 2 ; j <= K ; ++j)
            {
                dp[i][j] = binary_valley(i, j, dp);
            }
        }
        return dp[N][K];
    }
    int binary_valley(int floors, int eggs, vector<vector<int>> &dp)
    {
        int l = 1;
        int r = floors;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            int broken = dp[mid-1][eggs-1];
            int not_broken = dp[floors-mid][eggs];
            if (not_broken > broken)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
            
        }
        return max(dp[r-1][eggs-1], dp[floors-r][eggs]) + 1;
    }
};

int main()
{
    int N = 100;
    int K = 100;
    Solution sol;
    sol.superEggDrop(K,N);
    return 0;
}
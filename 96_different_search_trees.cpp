#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n+1; ++i) {
            int num = 0;
            for (int root = 1; root <= i; root++)
            {
                int left = root -1;
                int right = i - root;
                num += dp[left] * dp[right];
            }
            dp[i] = num;
        }
        return dp[n];
    }
};

int main()
{
    Solution s;

    cout << s.numTrees(3) <<endl;

    system("pause");
    return 0;
}
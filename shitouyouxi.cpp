#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int stone_game(vector<int> piles)
{
    int l = piles.size();
    if (l == 0) return 0;
    vector<vector<pair<int, int> > > dp(l, vector<pair<int, int> >(l, {0,0}));
    for (int i = 0; i < l; ++i)
    {
        dp[i][i].first = piles[i];
    }

    for (int i = 1; i < l; ++i)
    {
        for (int start = 0; start < l - i; ++start)
        {
            int end = start + i;
            int left = piles[start] + dp[start + 1][end].second;
            int right = piles[end] + dp[start][end - 1].second;
            if (left > right)
            {
                dp[start][end].first = left;
                dp[start][end].second = dp[start + 1][end].first;
            }
            else
            {
                dp[start][end].first = right;
                dp[start][end].second = dp[start][end - 1].first;
            }
        }
    }
    auto res = dp[0][l-1];
    return res.first - res.second;
}

int main()
{
    vector<int> piles = {3, 9, 1, 2};
    int ans = stone_game(piles);
    cout << ans << endl;
    return 0;
}
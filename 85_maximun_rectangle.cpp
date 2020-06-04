#include <vector>
#include <iostream>
#include <math.h>
#include <utility>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:


    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int h = matrix.size();
        if (h == 0) return 0;
        int w = matrix[0].size();
        if (w == 0) return 0;

        //创建柱状图
        vector<vector<int> > v(h, vector<int> (w));
        for (int i = 0; i < h; ++i) 
        {
            for (int j = 0; j < w; ++j) 
            {
                if (matrix[i][j] == '1') 
                {
                    if (j == 0) v[i][j] =1;
                    else v[i][j] = v[i][j-1] + 1;
                }
            }
        }
        
        int ans = 0;

        for (int j = 0; j < w; ++j) 
        {
            stack<pair<int, int>> s1;
            stack<pair<int, int>> s2;
            vector<int> left(h);
            vector<int> right(h);
            s1.push(make_pair(-1, -1));
            for (int i = 0; i < h; ++i) 
            {
                while (s1.top().second >= v[i][j])
                {
                    s1.pop();
                }
                left[i] = s1.top().first;
                s1.push(make_pair(i, v[i][j]));
            }
            s2.push(make_pair(h, -1));
            for (int i = h-1; i >= 0; --i)
            {
                while (s2.top().second >= v[i][j])
                {
                    s2.pop();
                }
                right[i] = s2.top().first;
                s2.push(make_pair(i, v[i][j]));
            }
            
            for (int i = 0; i < h; ++i)
            {
                int area = (right[i] - left[i] - 1) * v[i][j];
                if (area > ans)
                {
                    ans = area;
                }
            }
            int b = 0;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<vector<char>> m = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };

    cout << s.maximalRectangle(m) <<endl;

    system("pause");
    return 0;
}
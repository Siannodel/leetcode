#include<vector>

using namespace std;

class Solution {
public:
    void func(vector<vector<int>>& matrix, int n, vector<int> &res)
    {
        int h = matrix.size();
        int w = matrix[0].size();
        
        int left = n;
        int right = w-n-1;
        int top = n;
        int bottom = h-n-1;

        for (int i = left; i <= right; i++)
        {
            res.push_back(matrix[top][i]);
        }
        for (int j = top+1; j <= bottom; j++)
        {
            res.push_back(matrix[j][right]);
        }
        if (left >= right || top >= bottom)
        {
            return;
        }
        for (int i = right-1; i >= left; i--)
        {
            res.push_back(matrix[bottom][i]);
        }
        for (int j = bottom-1; j >= top+1; j--)
        {
            res.push_back(matrix[j][left]);
        }
        return;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if (h == 0) return {};
        int w = matrix[0].size();

        int c = (min(h,w)+1)/2;
        vector<int> res;
        for (int i = 0; i < c; i++)
        {
            func(matrix, i, res);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution sol;
    sol.spiralOrder(matrix);
}
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void print_vec(vector<T> v)
{
    if (v.size() == 0)
    {
        cout << "[]";
        return;
    }

    cout << "[";
    for (int i = 0; i < v.size() - 1; ++i)
    {
        cout<< v[i] <<",";
    }
    cout << v[v.size()-1] << "]";
    return;
}

template <typename T>
void print_vec2d(vector<vector<T>> v)
{
    if (v.size() == 0)
    {
        cout << "[]";
        return;
    }

    cout << "[";
    for (int i = 0; i < v.size() - 1; ++i)
    {
        print_vec(v[i]);
        cout << "," << endl;
    }
    print_vec(v[v.size() - 1]);
    cout << "]";
    return;
}

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        vector<vector<int>> map;
        int h = mat.size();
        if (h == 0) return 0;
        int w = mat[0].size();
        if (w == 0) return 0;
        get_integral_map(mat, map);

        print_vec2d(map);
        cout<<endl;

        int n = h < w ? h : w;
        while (n > 0)
        {
            bool flag = fun1(map, n, threshold);
            if (flag) return n;
            --n;
        }
        return 0;
    }
    bool fun1(vector<vector<int>>& map, int n, int threshold)
    {
        for (int i = n; i < map.size(); ++i)
        {
            for (int j = n; j < map[i].size(); ++j)
            {
                int sum = map[i][j] - map[i][j-n] - map[i-n][j] + map[i-n][j-n];
                cout << n << " , " << i-n << " , "<< j-n << " , "<< sum << endl;
                if (sum <= threshold) return true;
            }
        }
        return false;
    }

    void get_integral_map(vector<vector<int>>& mat, vector<vector<int>>& map)
    {
        map = vector<vector<int>>(mat.size() + 1, vector<int>(mat[0].size() + 1, 0));
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                map[i+1][j+1] = map[i+1][j] + map[i][j+1] - map[i][j] + mat[i][j];
            }
        }
        return;
    }

};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{1,1,3,2,4,3,2},
                               {1,1,3,2,4,3,2},
                               {1,1,3,2,4,3,2}};
    int threshold = 4;
    int result = s.maxSideLength(mat,threshold);
    cout<< result<<endl;
}
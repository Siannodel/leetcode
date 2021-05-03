#include <vector>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        if (num == 0) return 1;

        vector<int> v;
        while(num)
        {
            v.push_back(num%10);
            num /= 10;
        }

        int a = 1;
        int b = 1;
        for (int i = 1; i < v.size(); i++)
        {
            int tmp;
            if (v[i-1]*10 + v[i] <= 25)
            {
                tmp = a + b;
            }
            else
            {
                tmp = b;
            }
            a = b;
            b = tmp;
        }
        return b;
    }
};

int main()
{
    Solution sol;
    sol.translateNum(25);
    return 0;
}
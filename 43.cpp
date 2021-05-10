#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        vector<int> ans(l1+l2, 0);
        for (int i = l1-1; i >= 0; i--)
        {
            int n1 = num1[i] - '0';
            for (int j = l2-1; j >= 0; j--)
            {
                int n2 = num2[j] - '0';
                int mul = n1 * n2;
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = mul + ans[p2];
                ans[p2] = sum % 10;
                ans[p1] += sum / 10;
            }
        }
        int i = 0;
        while(i < ans.size() && ans[i] == 0)
        {
            i++;
        }
        string res;
        for (; i < ans.size(); i++)
        {
            res.push_back(char(ans[i]+'0'));
        }
        return res.size() == 0 ? "0" : res;
    }
};

int main()
{
    Solution sol;
    string s1 = "0";
    string s2 = "0";
    sol.multiply(s1, s2);
    return 0;
}
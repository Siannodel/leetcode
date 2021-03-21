#include <limits.h>

class Solution {
public:

    int helper(int a, int b)
    {
        if (a < b) return 0;
        int ans = 1;
        int acc = b;
        while(a-acc >= acc)
        {
            ans += ans;
            acc += acc;
        }
        return ans + helper(a-acc, b);
    }

    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;

        //在除数为-1且被除数是-2^31时
        if (divisor  == -1)
            return (dividend == INT_MIN) ? INT_MAX : -dividend;
        int a = dividend;
        int b = divisor;
        int ans = 0;
        bool flag = (a > 0 && b > 0 || a < 0 && b < 0);

        if (b == INT_MIN)
            return (a == INT_MIN) ? 1 : 0;
        if (a == INT_MIN)
        {
            a = (flag) ? a - b : a + b;
            ++ans;
        }

        a = (a > 0)? a : -a; 
        b = (b > 0)? b : -b;
        ans += helper(a, b);
        if(!flag) ans = -ans;
        return ans;
    }
};

class Solution2 {
public:

    int helper(int a, int b)
    {
        if (a > b) return 0;
        int ans = 1;
        int acc = b;
        while(a-acc <= acc)
        {
            ans += ans;
            acc += acc;
        }
        return ans + helper(a-acc, b);
    }

    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;

        //在除数为-1且被除数是-2^31时
        if (divisor  == -1)
            return (dividend == INT_MIN) ? INT_MAX : -dividend;
        int a = dividend;
        int b = divisor;
        int ans = 0;
        bool flag = (a > 0 && b > 0 || a < 0 && b < 0);


        a = (a < 0)? a : -a; 
        b = (b < 0)? b : -b;
        ans = helper(a, b);
        if(!flag) ans = -ans;
        return ans;
    }
};
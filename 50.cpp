class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        long long N = n;
        bool flag = false;
        if (n < 0)
        {
            N = -n;
            flag = true;
        }
        while(N)
        {
            if (N & 1)
            {
                result = result * x;
            }
            x = x * x;
            N = N >> 1;
        }

        if (flag)
        {
            result = 1 / result;
        }
        return result;
    }
};
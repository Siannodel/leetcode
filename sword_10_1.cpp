class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int n1 = 0;
        int n2 = 1;
        
        for (int i = 2; i <= n; i++)
        {
            int n3 = (n1 + n2) % 1000000007;
            n1 = n2;
            n2 = n3;
        }
        return n2;
    }
};
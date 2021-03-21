class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0)
        {
            a = a ^ b;
            b = a & b;
            b <<= 1;
        }
        return a;
    }
};
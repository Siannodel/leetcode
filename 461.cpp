

class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming_d = 0;
        int tmp = x ^ y;
        while(tmp > 0)
        {
            if (tmp & 1)
            {
                ++hamming_d;
            }
            tmp >>= 1;
        }
        return hamming_d;
    }
};
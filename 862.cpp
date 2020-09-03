#include <vector>
#include <deque>
#include <math.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> sum(A.size()+1, 0);
        for (int i = 0; i < A.size(); ++i)
        {
            sum[i+1] = sum[i] + A[i];
        }

        deque<int> P;
        int min_l = A.size() + 1;
        for (int i = 0; i < sum.size(); ++i)
        {
            while(!P.empty() && sum[i] <= sum[P.back()])
            {
                P.pop_back();
            }
            while(!P.empty() && sum[i] - sum[P.front()] >= K)
            {
                min_l = min(i-P.front(), min_l);
                P.pop_front();
            }
            P.push_back(i);
        }
        if (min_l > A.size()) min_l = -1;
        return min_l;
    }
};
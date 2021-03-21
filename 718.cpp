#include<vector>
#include<math.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int> > dp(A.size(), vector<int>(B.size(), 0));
        int result = 0;
        for (int i = 0; i< A.size(); ++i)
        {
            for (int j = 0; j < B.size(); ++j)
            {
                if (i == 0 || j == 0)
                {
                    if (A[i] == B[j]) 
                        dp[i][j] = 1;
                }
                else
                {
                    if (A[i] == B[j]) 
                        dp[i][j] = dp[i-1][j-1] + 1;
                }
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};

class Solution1 {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        return max(helper(A,B), helper(B,A));
    }
    int helper(vector<int>& v1, vector<int>& v2) {
        int maxl = 0;
        for (int off = 0; off < v1.size()-1; ++off)
        {
            int l = 0;
            for (int i = 0; i + off < v1.size() && i < v2.size(); ++i)
            {
                if (v1[i+off] == v2[i])
                {
                    ++l;
                    maxl = max(maxl, l);
                }
                else
                {
                    l = 0;
                }
                
            }
        }
        return maxl;
    }
};

class Solution2 {
public:

    const int mod = 1000000009;
    //选1个比取值范围大的素数
    const int base = 113;

    //使用快速幂计算 x^n % mod 的值
    //复杂度O(logn)
    long long qPow(long long x, long long n)
    {
        long long ret = 1;
        while(n)
        {
            if (n&1)
            {
                ret = ret * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return ret;
    }
    //检查A与B中是否有长度为len的子串重复
    bool check(vector<int> &A, vector<int> &B, int len)
    {
        unordered_set<long long> bucketA;
        //计算起始位置的hashA
        long long hashA = 0;
        for (int i = 0; i < len; i++)
        {
            hashA = (hashA * base + A[i]) % mod;
        }
        bucketA.insert(hashA);
        long long mult = qPow(base, len - 1);
        for (int i = len; i < A.size(); ++i)
        {
            //前一个(hashA - base^(len-1) * S[0]) * base + S[len]
            hashA = ((hashA - A[i-len]*mult % mod + mod) % mod * base + A[i]) % mod;
            bucketA.insert(hashA);
        }

        long long hashB = 0;
        for (int i = 0; i < len; ++i)
        {
            hashB = (hashB * base + B[i]) % mod;
        }
        if (bucketA.count(hashB)) {
            return true;
        }
        for (int i = len; i < B.size(); i++) {
            hashB = ((hashB - B[i - len] * mult % mod + mod) % mod * base + B[i]) % mod;
            if (bucketA.count(hashB)) {
                return true;
            }
        }
        return false;
    }

    int findLength(vector<int>& A, vector<int>& B) {
        //二分查找
        int left = 1, right = min(A.size(), B.size()) + 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(A, B, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
    
};
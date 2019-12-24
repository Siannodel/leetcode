#include <math.h>
/** 思路：
 * 只考虑正数情况，负数直接符号全反 结果一样
 * 首先是如何尽快能到达target
 * sum = 1+2+3+..+k 一定是 >= target 的
 * 运气好 正好等于 那么就是最快到达 步数为k
 * 其他情况，当首次大于的时候 target-sum为偶数，那么可以将 (target-sum)/2的数调整为负 就能到达 步数还是k 易见 在这种情况下也必然是最快到达
 * 当首次大于 但target-sum为奇数时，如何让其到达target，其实也可以考虑继续往上加，直到到达第一个target-sum为偶数的时候， 然后按照之前的办法到达就可以，
 * 因为加的数是奇偶交替的 所有要么1步变偶数 要么2步变偶数，变成偶数就可以以相同的步数到达target
 * 最后在这种情况下，还要看是否是最快到达，其实也可以发现，如果target-sum为奇数的时候，由于每次改变正负号距离改变都是偶数，因此肯定是无法到达的，所以也是最快到达
 * 综上，其实就是一直加 加到大于等于target且第一次sum-target为偶数的情况下，就是能够到达的最小步数。
 */
class Solution {
public:
    int reachNumber(int target) {
        int sum = 0;
        target = abs(target);
        int k = 0;
        while(true){
            if(sum >= target && (sum-target)%2 == 0){
                break;
            }
            k++;
            sum += k;
        }
        return k;
    }
};
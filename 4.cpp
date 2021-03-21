#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:

    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        if (k > nums1.size() + nums2.size()) return -1;
        int l1 = nums1.size();
        int l2 = nums2.size();
        int left1 = 0;
        int left2 = 0;

        while(true)
        {
            if (left1 >= l1)
            {
                return nums2[left2 + k - 1];
            }
            if (left2 >= l2)
            {
                return nums1[left1 + k - 1];
            }
            if (k == 1)
            {
                return min(nums1[left1], nums2[left2]);
            }
            int i1 = min(left1 + k/2 - 1, l1 - 1);
            int i2 = min(left2 + k/2 - 1, l2 - 1);
            if (nums1[i1] <= nums2[i2])
            {
                k -= i1 + 1 - left1;
                left1 = i1 + 1;
            }
            else
            {
                k -= i2 + 1 - left2;
                left2 = i2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size() + nums2.size();
        if (l % 2 == 1)
        {
            return getKthElement(nums1, nums2, (l+1)/2);
        }
        else
        {
            return (getKthElement(nums1, nums2, l/2) + getKthElement(nums1, nums2, l/2+1))/2.0;
        }
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        int l = 0;
        for(int i = 1; i < n; i++)
        {
            if (height[i-1] > l)
            {
                l = height[i-1];
            }
            left_max[i] = l;
        }
        int r = 0;
        for (int i = n-2; i >= 0; i--)
        {
            if (height[i+1]>r)
            {
                r = height[i+1];
            }
            right_max[i] = r;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp = min(right_max[i], left_max[i])- height[i];
            ans += tmp > 0 ? tmp : 0;
        }
        return ans;
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int ans = 0;
        int l_max = height[0];
        int r_max = height[n-1];
        while(left <= right)
        {
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);

            if (l_max < r_max)
            {
                int tmp = l_max - height[left];
                ans += tmp > 0 ? tmp : 0;
                left ++;
            }
            else
            {
                int tmp = r_max - height[right];
                ans += tmp > 0 ? tmp : 0;
                right --;
            }
        }
        return ans;
    }
};
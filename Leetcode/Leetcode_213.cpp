// 打家劫舍II
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+1, nums.end());
        int first = helper(nums1);
        int second = helper(nums2);
        return max(first, second);
    }

    int helper(vector<int> & nums) {
        int cur = 0, pre = 0;
        for(int num: nums) {
            int temp = pre;
            pre = cur;
            cur = max(temp + num, cur);
        }
        return cur;
    }
};

// 遍历两次
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp1(n - 1, 0);
        vector<int> dp2(n - 1, 0);
        dp1[0] = nums[0];
        dp2[0] = nums[1];
        dp1[1] = max(nums[0], nums[1]);
        dp2[1] = max(nums[1], nums[2]);
        for (int i = 2; i < n - 1; ++i) dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
        for (int i = 3; i < n; ++i) dp2[i-1] = max(dp2[i-2], dp2[i-3] + nums[i]);
        return max(dp1[n-2], dp2[n-2]);
    }
};
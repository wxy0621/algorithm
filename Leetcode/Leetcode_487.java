// 最大连续1的个数 II
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return 1;
        int res = 0;
        int dp1 = 0, dp0 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                dp1 = dp0 + 1;
                dp0 = 0;
            } else {
                dp0 = dp0 + 1;
                dp1 = dp1 + 1;
            }
            res = Math.max(res, Math.max(dp0, dp1));
        }
        return res;
    }
}
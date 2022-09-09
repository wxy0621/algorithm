// 和大于等于 target 的最短子数组
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int i = 0, j = 0;
        int res = INT_MAX;
        int total = nums[0];
        while (i <= j) {
            if (total >= target) {
                res = min(res, j - i + 1);
                total -= nums[i];
                ++i;
            } else {
                if (j == n - 1) break;
                ++j;
                total += nums[j];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
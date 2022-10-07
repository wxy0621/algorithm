// 最大升序子数组和
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int total = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                total += nums[i];
                res = max(res, total);
            } else {
                total = nums[i];
            }
        }
        return res;
    }
};
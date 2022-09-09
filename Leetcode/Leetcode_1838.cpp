// 最高频元素的频数
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 1;
        int i = 0;
        long long total = 0;
        for (int j = 1; j < n; ++j) {
            total += (long long)(nums[j] - nums[j-1]) * (j - i);
            while (total > k) {
                total -= (nums[j] - nums[i]);
                ++i;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
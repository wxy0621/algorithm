// 差的绝对值为 K 的数对数目
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] - nums[i] == k) {
                    ++res;
                }
            }
        }
        return res;
    }
};
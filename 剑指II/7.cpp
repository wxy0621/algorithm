// 数组中和为 0 的三个数
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        vector<vector<int>> res;
        int j, k;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            j = i + 1;
            k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j-1]) ++j;
                    while (j < k && nums[k] == nums[k+1]) --k;
                } else if (nums[i] + nums[j] + nums[k] < 0) ++j;
                else if (nums[i] + nums[j] + nums[k] > 0) --k;
            }
        }
        return res;
    }
};
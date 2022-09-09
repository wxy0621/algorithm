// 连续数组
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int sum = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) nums[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum == 0 && i > res) {
                res = i + 1;
            }
            if (m.count(sum)) {
                res = max(res, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return res;
    }
};
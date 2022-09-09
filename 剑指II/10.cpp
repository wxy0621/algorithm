// 和为 k 的子数组
// 因为数字可正可负，因为只能采用前缀和，不能滑动窗口
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0;
        int preSum = 0;
        for (auto& num: nums) {
            preSum += num;
            if (m.count(preSum - k)) {
                res += m[preSum - k];
            }
            ++m[preSum];
        }
        return res;
    }
};
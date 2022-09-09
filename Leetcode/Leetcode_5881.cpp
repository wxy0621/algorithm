// 增量元素之间的最大差值
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;
        int res = -1;
        int minNum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > minNum) res = max(res, nums[i] - minNum);
            minNum = min(minNum, nums[i]);
        }
        return res;
    }
};

// 消失的数字
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            res ^= i;
            res ^= nums[i];
        }
        res ^= n;
        return res;
    }
};
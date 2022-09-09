// 连续的子数组和
// 试例太蠢了
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return false;
        if(k == 0) { // 分为 k == 0
            int i = 0;
            while(i < n - 1) {
                if(nums[i] + nums[i + 1] == 0) return true;
                ++i;
            }
            return false;
        } // 和 k ！= 0 两种情况
        for(int i = 0; i < n; ++i) {
            int sum = nums[i];
            for(int j = i + 1; j < n; ++j) {
                sum += nums[j];
                if(sum % k == 0) return true;
            }
        }
        return false;
    }
};
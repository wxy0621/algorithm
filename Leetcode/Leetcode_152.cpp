// 乘积最大子数组
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_temp = nums[0], min_temp = nums[0];
        int res = max_temp;
        for(int i = 1; i < nums.size(); ++i) {
            int max_t = max_temp, min_t = min_temp;
            max_temp = max(max_t * nums[i], max(nums[i], min_t * nums[i]));
            min_temp = min(min_t * nums[i], min(nums[i], max_t * nums[i]));
            res = max(max_temp, res);
        }
        return res;
    }
};
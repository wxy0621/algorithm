// 除自身以外数组的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res = {1};
        int n = nums.size();
        int temp = 1;
        int temp2 = 1;
        for(int i = 0; i < n - 1; ++i) {
            temp *= nums[i];
            res.emplace_back(temp);
        }
        for(int i = n - 1; i > 0; --i) {
            temp2 *= nums[i];
            res[i - 1] *= temp2;
        }
        return res;
    }
};
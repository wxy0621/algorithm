// 缺失数字
// 位运算
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            res ^= i ^ nums[i];
        }
        return res;
    }
};

// 求和
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 1; i <= nums.size(); ++i) {
            res += (i - nums[i - 1]);
        }
        return res;
    }
};
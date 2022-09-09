// 递增的三元子序列
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int minNum = INT_MAX;
        int secondNum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= minNum) {
                minNum = nums[i];
            } else if (nums[i] <= secondNum) {
                secondNum = nums[i];
            } else if (nums[i] > secondNum) {
                return true;
            }
        }
        return false;
    }
};
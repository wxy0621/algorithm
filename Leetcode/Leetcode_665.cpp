// 非递减数列
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] > nums[i + 1]) {
                if(i == 0) nums[0] = nums[1];
                else if(nums[i - 1] > nums[i + 1]) nums[i + 1] = nums[i];
                else nums[i] = nums[i + 1];
                break;
            }
        }
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i - 1] > nums[i]) return false;
        }
        return true;
    }
};
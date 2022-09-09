// 跳跃游戏
// 贪心法的两种不同思路
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int temp_max = 0;
        for(int i = 0; i < n; ++i) {
            if(temp_max >= i) {
                temp_max = max(temp_max, i + nums[i]);
                    if(temp_max >= n - 1)
                        return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int k = 0; // k表示最远起跳点
        for(int i = 0; i < n; ++i) {
            if(i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
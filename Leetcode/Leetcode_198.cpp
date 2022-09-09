// 打家劫舍
// 动态规划
class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0, cur = 0;
        for(int num: nums) {
            int temp = pre;
            pre = cur;
            cur = max(cur, temp + num);
        }
        return cur;
    }
};
// 摆动序列
// 波峰波谷高度只差1
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int up = 1, down = 1;
        for(int i = 1; i < n; ++i) {
            if(nums[i] > nums[i - 1]) up = down + 1;
            if(nums[i] < nums[i - 1]) down = up + 1;
        }
        return max(up, down);
    }
};

// 贪心法
// 说实话，没太懂
class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int pre = nums[1] - nums[0];
        int count = (pre == 0 ? 1 : 2);
        for(int i = 1; i < n; ++i) {
            int temp = nums[i] - nums[i - 1];
            if((temp > 0 && pre <= 0) || (temp < 0 && pre >= 0)) {
                ++count;
                pre = temp;
            }
        }
        return count;
    }
};
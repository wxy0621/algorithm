// 数组中两元素的最大乘积
// 求最大和第二大值
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int max_num = INT_MIN;
        int second_num = INT_MIN;
        for(int i = 0; i < n; ++i) {
            if(nums[i] > max_num) {
                second_num = max_num;
                max_num = nums[i];
            } else if(nums[i] > second_num) {
                second_num = nums[i];
            }
        }
        return (max_num - 1) * (second_num - 1);
    }
};

// 排序
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        sort(nums.begin(), nums.end());
        return (nums[n - 1]- 1) * (nums[n - 2] - 1);
    }
};
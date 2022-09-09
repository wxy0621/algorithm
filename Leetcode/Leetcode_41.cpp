// 缺失的第一个正数
// 困难题，原地哈希表
// 基本思路：利用元素值的关系找到满足条件的index
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 将小于等于 0 的数变为 n + 1， 方便下一步操作
        for(int& num: nums) {
            if(num <= 0)
                num = n + 1;
        }
        // 核心步骤，将满足条件的值所对应的 索引-1 的值变为负数，不影响该位置值的操作，但凸显了不同的特征
        for(int i = 0; i < n; ++i) {
            int temp = abs(nums[i]);
            if(temp <= n) {
                nums[temp - 1] = -abs(nums[temp - 1]);
            }
        }
        // 第一个不为负的即为满足要求的确实的最小正数
        for(int i = 0; i < n; ++i) {
            if(nums[i] > 0)
                return i + 1;
        }
        // 当 1-n 都有，返回 n+1
        return n + 1;
    }
};
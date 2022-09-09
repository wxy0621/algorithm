// 和相同的二元子数组
// 前缀和
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0;
        int n = nums.size();
        unordered_map<int, int> um;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            ++um[sum];
            sum += nums[i];
            res += um[sum - goal];
        }
        return res;
    }
};

// 滑动窗口有点复杂
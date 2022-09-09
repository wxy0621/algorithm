// 统计「优美子数组」
// 前缀和
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum = 0;
        vector<int> pre(n + 1);
        pre[0] = 1;
        for(int i = 0; i < n; ++i) {
            sum += nums[i] & 1;
            ++pre[sum];
            if(sum >= k) count += pre[sum - k];
        }
        return count;
    }
};
// 长度最小的子数组
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int i = 0, j = 0;
        int res = 0;
        int max_temp = 0;
        while(j < n) {
            max_temp += nums[j];
            while(max_temp >= s) {
                if(res == 0) res = j - i + 1;
                res = min(res, j - i + 1);
                max_temp -= nums[i];
                ++i;
            }
            ++j;
        }
        return res;
    }
};
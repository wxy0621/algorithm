// 最长连续序列
// 哈希表
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        int res = 0;
        for(const int& num: nums) {
            us.insert(num);
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(!us.count(nums[i] - 1)) {
                int temp_max = 1;
                int temp_num = nums[i];
                while(us.count(temp_num + 1)) {
                    ++temp_max;
                    ++temp_num;
                }
                res = max(temp_max, res);
            }
        }
        return res;
    }
};
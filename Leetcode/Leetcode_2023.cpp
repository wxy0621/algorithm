// 连接后等于目标字符串的字符串对
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (nums[i].size() + nums[j].size() != target.size()) continue;
                if (nums[i] + nums[j] == target) ++res;
            }
        }
        return res;
    }
};
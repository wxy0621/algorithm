// 随机数索引
class Solution {
public:
    Solution(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (m.count(nums[i])) {
                m[nums[i]].emplace_back(i);
            } else {
                m[nums[i]] = {i};
            }
        }
    }
    
    int pick(int target) {
        if (!m.count(target)) return -1;
        return m[target][rand() % m[target].size()];
    }
private:
    unordered_map<int, vector<int>> m;
};
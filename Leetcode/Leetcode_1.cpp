// 两数之和
// 对 hashmap 的不同操作
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) m[nums[i]] = i;
        for (int i = 0; i < n - 1; ++i) {
            if (m.count(target - nums[i]) && m[target - nums[i]] != i) {
                return {i, m[target - nums[i]]};
            }
        }
        return {};
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) m[nums[i]] = i;
        for (int i = 0; i < n - 1; ++i) {
            if (m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i) {
                return {i, m[target - nums[i]]};
            }
        }
        return {};
    }
};

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

// 池塘抽样（但超时了）
class Solution2 {
public:
    Solution(vector<int>& _nums): nums(_nums), n(nums.size()) { }
    
    int pick(int target) {
        int res;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                if (rand() % ++cnt == 0) {
                    res = i;
                }
            }
        }
        return res;
    }
private:
    vector<int>& nums;
    int n;
};
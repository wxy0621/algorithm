// 存在重复元素II
// 哈希表
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i) {
            auto iter = m.find(nums[i]);
            if(iter != m.end()) {
                if(i - iter->second <= k)
                    return true;
                else
                    m[nums[i]] = i;
            } else 
                m[nums[i]] = i;
        }
        return false;
    }
};
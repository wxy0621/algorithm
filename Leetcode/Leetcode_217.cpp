// 存在重复元素
// hash
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(int& num: nums) {
            us.insert(num);
        }
        return nums.size() != us.size();
    }
};

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto& num: nums) {
            if (s.count(num)) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};
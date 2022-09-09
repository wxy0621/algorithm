// 只出现一次的数字 III
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> us;
        for (auto& num: nums) {
            if (us.find(num) != us.end()) us.erase(num);
            else us.insert(num);
        }
        for (auto& num: us) res.emplace_back(num);
        return res;
    }
};
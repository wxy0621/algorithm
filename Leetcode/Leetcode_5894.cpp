// 至少在两个数组中出现的值
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res;
        unordered_set<int> s1;
        unordered_set<int> s2;
        unordered_set<int> resSet;
        for (auto& num: nums1) {
            s1.insert(num);
        }
        for (auto& num: nums2) {
            if (s1.count(num)) resSet.insert(num);
            s2.insert(num);
        }
        for (auto& num: nums3) {
            if (s1.count(num)) resSet.insert(num);
        }
        for (auto& num: nums3) {
            if (s2.count(num)) resSet.insert(num);
        }
        for (auto& num: resSet) {
            res.emplace_back(num);
        }
        return res;
    }
};

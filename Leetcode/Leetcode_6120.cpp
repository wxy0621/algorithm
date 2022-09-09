// 数组能形成多少数对
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int countNum = 0;
        int resNum = 0;
        unordered_set<int> s;
        for (auto& num: nums) {
            if (s.count(num)) {
                ++countNum;
                s.erase(num);
            } else {
                s.insert(num);
            }
        }
        for (auto& num: s) {
            if (s.count(num)) {
                ++resNum;
            }
        }
        return vector<int>{countNum, resNum};
    }
};
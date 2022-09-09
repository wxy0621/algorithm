// 数组中的K-diff数对
// 哈希表
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int count = 0;
        unordered_map<int, int> m;
        for(int& num: nums) ++m[num];
        for(auto& num: m) {
            if(k == 0) {
                if(num.second > 1) ++count;
            } else {
                if(m.find(num.first - k) != m.end()) ++count;
            }
        }
        return count;
    }
};
// 好数对的数目
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for(auto& num: nums) ++m[num];
        for(auto& t: m) {
            int temp = t.second;
            res += temp * (temp - 1) / 2;
        }
        return res;
    }
};
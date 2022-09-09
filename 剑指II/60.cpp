// 出现频率最高的 k 个数字
class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        vector< pair<int, int> > count;
        unordered_map<int, int> m;
        for (auto& num: nums) ++m[num];
        for (auto& t: m) {
            count.emplace_back(pair<int, int>{t.first, t.second});
        }
        sort(count.begin(), count.end(), cmp);
        for (auto& t: count) {
            res.emplace_back(t.first);
            if (--k == 0) break;
        }
        return res;
    }
};
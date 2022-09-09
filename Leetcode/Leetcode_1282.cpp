// 用户分组
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        int n = groupSizes.size();
        unordered_map<int, vector<int> > m;
        for (int i = 0; i < n; ++i) {
            if (m.count(groupSizes[i])) {
                m[groupSizes[i]].emplace_back(i);
            } else {
                m[groupSizes[i]] = vector<int>{i};
            }
            if (m[groupSizes[i]].size() == groupSizes[i]) {
                res.emplace_back(m[groupSizes[i]]);
                m[groupSizes[i]] = {};
            }
        }
        return res;
    }
};
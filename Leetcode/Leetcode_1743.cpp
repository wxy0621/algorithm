// 从相邻元素对还原数组
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        vector<int> res(n);
        unordered_map< int, vector<int> > m;
        for (auto& adjacentPair: adjacentPairs) {
            m[adjacentPair[0]].emplace_back(adjacentPair[1]);
            m[adjacentPair[1]].emplace_back(adjacentPair[0]);
        }
        for (auto& temp: m) {
            if (temp.second.size() == 1) {
                res[0] = temp.first;
                break;
            }
        }
        res[1] = m[res[0]][0];
        for (int i = 2; i < n; ++i) {
            auto& temp = m[res[i-1]];
            res[i] = res[i-2] == temp[0] ? temp[1] : temp[0];
        }
        return res;
    }
};
// 字典序排数
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        map<string, int> m;
        for (int i = 1; i <= n; ++i) m[to_string(i)] = i;
        for (auto it = m.begin(); it != m.end(); ++it) res.emplace_back(it->second);
        return res;
    }
};
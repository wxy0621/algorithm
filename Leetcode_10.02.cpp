// 变位词组
// hash
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        vector<vector<string>> res;
        unordered_map<long long, vector<string>> m;
        for (int i = 0; i < n; ++i) {
            int len = strs[i].size();
            long long temp = 1;
            int mod = 1e9 + 7;
            for (int j = 0; j < len; ++j) {
                int index = strs[i][j] - 'a';
                temp = ((temp % mod) * (primes[index] % mod)) % mod;
            }
            if (m.count(temp)) m[temp].emplace_back(strs[i]);
            else m[temp] = {strs[i]};
        }
        for (auto& t: m) {
            res.emplace_back(t.second);
        }
        return res;
    }
};
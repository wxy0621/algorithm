// 变位词组
// hash
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> myMap;
        for (auto& str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            myMap[key].emplace_back(str);
        }
        for (auto& m: myMap) {
            res.emplace_back(m.second);
        }
        return res;
    }
};
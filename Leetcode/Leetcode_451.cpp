// 根据字符出现频率排序
// 对 哈希表排序 的一种办法
class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> m;
        vector< pair<char, int> > v;
        for(auto& c: s) ++m[c];
        for(auto& t: m) v.emplace_back(t);
        sort(v.begin(), v.end(), [](pair<char, int> p1, pair<char, int> p2) {return p1.second > p2.second;});
        for(auto& t: v) res += string(t.second, t.first);
        return res;
    }
};
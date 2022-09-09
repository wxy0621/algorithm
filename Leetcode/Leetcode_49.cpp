// 字母异位词分组
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector< vector<string> > res;
        // m 的 int 存储每类字符串的序号，从 0 开始计数
        unordered_map<string, int> m;
        string temp;
        int i = 0;
        for(string s: strs) {
            temp = s;
            sort(temp.begin(), temp.end());
            if(m.count(temp)) {
                res[m[temp]].emplace_back(s);
            } else {
                vector<string> v;
                v.emplace_back(s);
                res.emplace_back(v);
                m[temp] = i++;
            }
        }
        return res;
    }
};
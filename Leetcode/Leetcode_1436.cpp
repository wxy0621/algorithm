// 旅行终点站
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        string res;
        for(auto& str: paths) m[str[0]] = str[1];
        string key = paths[0][0];
        while(m.find(key) != m.end()) {
            key = m[key];
        }
        return key;
    }
};

class Solution2 {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        string res;
        for(auto& str: paths) m[str[0]] = str[1];
        string key = paths[0][0];
        while(m.count(key)) {
            key = m[key];
        }
        return key;
    }
};
// 键值映射
class MapSum {
public:
    map<string, int> m;
    /** Initialize your data structure here. */
    MapSum() = default;
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            string s = it->first;
            if (s.find(prefix) == 0) {
                res += it->second;
            }
        }
        return res;
    }
};
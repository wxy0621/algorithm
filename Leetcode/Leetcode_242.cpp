// 有效的字母异位词
// 排序
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// 哈希表
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> um;
        for(char& c: s) ++um[c];
        for(char& c: t) --um[c];
        for(auto temp :um) if(temp.second != 0) return false;
        return true;
    }
};
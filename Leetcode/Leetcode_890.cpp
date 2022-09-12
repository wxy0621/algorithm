// 查找和替换模式
class Solution {
public:
    bool filterWords(string str1, string str2) {
        if (str1.size() != str2.size()) return false;
        int n = str1.size();
        unordered_map<char, char> m;
        for (int i = 0; i < n; ++i) {
            char c1 = str1[i], c2 = str2[i];
            if (!m.count(c1)) m[c1] = c2;
            else if (m[c1] != c2) {
                return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto& word: words) {
            if (filterWords(word, pattern) && filterWords(pattern, word)) res.emplace_back(word);
        }
        return res;
    }
};
// 词典中最长的单词
// hash
bool cmp(string& v1, string& v2) {
    if (v1.size() == v2.size()) return v1 > v2;
    return v1.size() < v2.size();
}
class Solution {
public:
    string longestWord(vector<string>& words) {
        if (words.size() == 0) return "";
        sort(words.begin(), words.end(), cmp);
        string res;
        unordered_set<string> s;
        s.insert("");
        for (auto& word: words) {
            if (s.count(word.substr(0, word.size() - 1))) {
                s.insert(word);
                res = word;
            }
        }
        return res;
    }
};
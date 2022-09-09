// 单词的压缩编码
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0;
        unordered_set<string> s(words.begin(), words.end());
        for(auto& word: words) {
            for(int i = 1; i < word.size(); ++i) s.erase(word.substr(i));
        }
        for(auto& word: s) res += word.size() + 1;
        return res;
    }
};
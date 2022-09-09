// 字符串中的单词数
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        bool newWord = true;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') newWord = true;
            else {
                if (newWord) {
                    ++res;
                    newWord = false;
                }
            }
        }
        return res;
    }
};
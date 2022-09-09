// 通过删除字母匹配到字典里最长单词
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        int n1 = s.size();
        for (auto& str: dictionary) {
            int n2 = str.size();
            int i = 0, j = 0;
            while (i < n1 && j < n2) {
                if (str[j] == s[i]) ++j;
                ++i;
            }
            if (j == n2) {
                if (res.size() < n2 || (res.size() == n2 && res > str)) {
                    res = str;
                }
            }
        }
        return res;
    }
};
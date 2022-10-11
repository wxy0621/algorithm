// T9键盘
class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> res;
        int keys[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
        for (auto& word: words) {
            if (word.size() != num.size()) continue;
            bool flag = true;
            for (int i = 0; i < num.size(); ++i) {
                if (keys[word[i]-'a'] + '0' != num[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.emplace_back(word);
        }
        return res;
    }
};
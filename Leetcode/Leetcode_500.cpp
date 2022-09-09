// 键盘行
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (auto& word: words) {
            uint8_t temp = 7;
            for (auto& c: word) {
                temp &= ht[tolower(c)-'a'];
                if (!temp) break;
            }
            if (temp) res.emplace_back(word);
        }
        return res;
    }
private:
    vector<uint8_t> ht = {2, 4, 4, 2, 1, 2, 2, 2, 1, 2, 
    2, 2, 4, 4, 1, 1, 1, 1, 2, 1, 1, 4, 1, 4, 1, 4};
};
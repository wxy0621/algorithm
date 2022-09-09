// 拼写单词
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        unordered_map<char, int> char_num;
        for(char& c: chars) ++char_num[c];

        for(string& word: words) {
            unordered_map<char, int> word_num;
            for(char& c: word) ++word_num[c];

            bool is_res = true;
            for(char& c: word) {
                if(word_num[c] > char_num[c]) {
                    is_res = false;
                    break;
                }
            }
            if(is_res) res += word.size();
        }

        return res;
    }
};
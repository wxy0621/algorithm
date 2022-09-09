// 最常见的单词
// 哈希表
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> word, ban;
        string str, res;
        int count_max = 0;
        for(auto& num: banned) ++ban[num];
        for(int i = 0; i < paragraph.size(); ++i) {
            while(isalpha(paragraph[i])) str += tolower(paragraph[i++]);
            if(ban[str] != 1 && str != "") {
                if(count_max < ++word[str]) {
                    count_max = word[str];
                    res = str;
                }
            }
            str.clear();
        }
        return res;
    }
};
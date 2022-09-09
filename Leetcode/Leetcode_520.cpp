// 检测大写字母
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(word[0] <= 'z' && word[0] >= 'a') {
            for(int i = 1; i < n; ++i) {
                if(word[i] <= 'Z' && word[i] >= 'A') return false;
            }
        }
        if(word[1] <= 'z' && word[1] >= 'a') {
            for(int i = 2; i < n; ++i) {
                if(word[i] <= 'Z' && word[i] >= 'A') return false;
            }
        } else {
            for(int i = 2; i < n; ++i) {
                if(word[i] <= 'z' && word[i] >= 'a') return false;
            }
        }
        return true;
    }
};
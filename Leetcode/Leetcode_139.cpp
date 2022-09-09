// 单词拆分
// 动态规划，dp[i] 表示 s 的前 i 位是否可以用 wordList 中的单词表示
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> word_dict;
        vector<bool> dp(n + 1);
        for(string word: wordDict) {
            word_dict.insert(word);
        }
        dp[0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && word_dict.find(s.substr(j, i - j)) != word_dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
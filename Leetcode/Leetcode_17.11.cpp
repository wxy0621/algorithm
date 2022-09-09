// 单词距离
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int first = INT_MIN / 3;
        int second = INT_MAX / 3;
        int res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) first = i;
            if (words[i] == word2) second = i;
            res = min(res, abs(first - second));
        }
        return res;
    }
};
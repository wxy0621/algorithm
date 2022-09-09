// 重复的DNA序列
// 哈希
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        unordered_map<string, int> cache;
        for (int i = 0; i <= n - 10; ++i) {
            string temp = s.substr(i, 10);
            ++cache[temp];
            if (cache[temp] == 2) {
                res.emplace_back(temp);
            }
        }
        return res;
    }
};

// 位运算 + 滑动窗口
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        int num = 0;
        unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        for (int i = 0; i < 9; ++i) {
            num = (num << 2) | bin[s[i]];
        }
        unordered_map<int, int> cache;
        for (int i = 9; i < n; ++i) {
            num = ((num << 2) | bin[s[i]]) & ((1 << 20) - 1);
            ++cache[num];
            if (cache[num] == 2) {
                res.emplace_back(s.substr(i - 9, 10));
            }
        }
        return res;
    }
};
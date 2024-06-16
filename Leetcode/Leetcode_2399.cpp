// 检查相同字母间的距离
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> firstIndex(26);
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (firstIndex[idx] && (i - firstIndex[idx] != distance[idx])) {
                return false;
            }
            firstIndex[idx] = i + 1;
        }
        return true;
    }
};
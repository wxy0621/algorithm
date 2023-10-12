// 使括号有效的最少添加
class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftCount = 0;
        int res = 0;
        for (auto& c: s) {
            if (c == '(') ++leftCount;
            else {
                if (leftCount == 0) ++res;
                else --leftCount;
            }
        }
        res += leftCount;
        return res;
    }
};
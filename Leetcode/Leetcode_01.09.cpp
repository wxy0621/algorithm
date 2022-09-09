// 字符串轮转
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 != n2) return false;

        return (s1 + s1).find(s2) != -1;
    }
};
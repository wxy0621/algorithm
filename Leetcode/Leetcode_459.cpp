// 重复的子字符串
// string 的 find 的第二个参数表示开始搜索的索引的位置，返回值为找到的目标值的第一个字符的索引s位置
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
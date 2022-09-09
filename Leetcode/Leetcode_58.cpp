// 最后一个单词的长度
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int n = s.size();
        bool flag = false;
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] != ' ')
                ++res;
            else if(res != 0)
                return res;
        }
        return res;
    }
};
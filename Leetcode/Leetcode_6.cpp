// Z字形变换
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string res;
        vector<string> temp(min(numRows, int(s.size())));
        int i = 0;
        int flag = false;
        for(char a: s) {
            temp[i] += a;
            if(i == 0 || i == numRows - 1) flag = !flag;
            i += flag ? 1 : -1;
        }
        for(string t: temp)
            res += t;
        return res;
    }
};
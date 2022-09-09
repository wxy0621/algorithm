// 生成每种字符都是奇数个的字符串
class Solution {
public:
    string generateTheString(int n) {
        string res;
        if(n % 2 == 1) {
            for(int i = 0; i < n; ++i) res += 'a';
        } else {
            for(int i = 0l; i < n - 1; ++i) res += 'a';
            res += 'b';
        }
        return res;
    }
};
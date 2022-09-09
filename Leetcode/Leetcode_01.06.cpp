// 字符串压缩
class Solution {
public:
    string compressString(string S) {
        int n = S.size();
        string res;
        int i = 0, j = 1;
        while(j < n) {
            if(S[i] != S[j]) {
                res += S[i];
                res += to_string(j - i);
                i = j;
            }
            j++;
        }
        res += S[i];
        res += to_string(j - i);
        
        return res.size() < n ? res : S;
    }
};
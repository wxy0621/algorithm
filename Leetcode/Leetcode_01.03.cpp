// URL化
class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res;
        for(int i = 0; i < length; ++i) {
            if(S[i] == ' ') res += "%20";
            else res += S[i];
        }
        return res;
    }
};

// 原地修改，莫名很快
class Solution2 {
public:
    string replaceSpaces(string S, int length) {
        int new_length = length;
        for(int i = 0; i < length; ++i) {
            if(S[i] == ' ') new_length += 2;
        }
        int k = new_length - 1, j = length - 1;
        while(j >= 0) {
            if(S[j] == ' ') {
                S[k--] = '0';
                S[k--] = '2';
                S[k--] = '%';
            } else {
                S[k--] = S[j];
            }
            --j;
        }
        return S.substr(0, new_length);
    }
};
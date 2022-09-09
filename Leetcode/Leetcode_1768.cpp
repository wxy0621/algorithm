// 交替合并字符串
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int n1 = word1.size(), n2 = word2.size();
        int i = 0;
        int j = 0;
        int flag = 0;
        while (i+j < n1+n2) {
            if (i == n1 || j == n2) flag = 2;
            if (flag == 0 && i < n1) {
                res += word1[i++];
                flag = 1;
            }
            else if (flag == 1 && j < n2) {
                res += word2[j++];
                flag = 0;
            } else {
                if (i < n1) res += word1[i++];
                if (j < n2) res += word2[j++];
            }
        }
        return res;
    }
};

// 精简版
class Solution2 {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int n1 = word1.size(), n2 = word2.size();
        int i;
        for (i = 0; i < n1 && i < n2; ++i) {
            res += word1[i];
            res += word2[i];
        }
        while (i < n1) res += word1[i++];
        while (i < n2) res += word2[i++];
        return res;
    }
};
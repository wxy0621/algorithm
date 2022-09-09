// 移掉 K 位数字
class Solution {
public:
    string removeKdigits(string num, int k) {
        for (int i = 0; i < k; ++i) {
            int n = num.size();
            if (n == 0 || n == 1 && num[i] == 0) return "0";
            int j = 0;
            while (j < n - 1 && num[j] <= num[j+1]) ++j;
            num = num.substr(0, j) + num.substr(j+1, n-j-1);
            while (num.size() > 0 && num[0] == '0') num = num.substr(1, n-1);
            if (num.size() == 0) return "0";
        }
        return num;
    }
};

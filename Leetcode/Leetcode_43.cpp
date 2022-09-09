// 字符串相乘
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string res(m + n, '0');
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int temp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] = temp % 10 + '0';
                res[i + j] += temp / 10;
            }
        }
        for(int i = 0; i < m + n; ++i) {
            if(res[i] != '0')
                return res.substr(i);
        }
        return "0";
    }
};
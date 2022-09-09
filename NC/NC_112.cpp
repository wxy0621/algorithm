// 进制转换
class Solution {
public:
    /**
     * 进制转换
     * @param M int整型 给定整数
     * @param N int整型 转换到的进制
     * @return string字符串
     */
    string solve(int M, int N) {
        // write code here
        string res = "";
        bool isPositive = true;
        if (M < 0) {
            isPositive = false;
            M = -M;
        }
        while (M) {
            int num = M % N;
            string str;
            if (num < 10) str = to_string(num);
            else {
                str = 'A' - 10 + num;
            }
            M /= N;
            res = str + res;
        }
        if (!isPositive) res = '-' + res;
        return res;
    }
};
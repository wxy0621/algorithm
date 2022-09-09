// 整数拆分
// 尽量多分解出 3，若最后余数为 1，则减一个 3， 分解为 2 *
// 记个结论，数学证明不想看了
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int res;
        int count_3 = n / 3;
        int remainder = n - (n / 3) * 3;
        if(remainder == 2) res = pow(3, count_3) * 2;
        else if(remainder == 1) res = pow(3, count_3 - 1) * 4;
        else if(remainder == 0) res = pow(3, count_3);
        return res;
    }
};
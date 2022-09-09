// 第 N 个泰波那契数
class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        if(n == 0) return a;
        if(n == 1) return b;
        while(n-2) {
            int temp1 = c, temp2 = b;
            c = a + b + c;
            b = temp1;
            a = temp2;
            --n;
        }
        return c;
    }
};
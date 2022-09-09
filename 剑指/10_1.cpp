// 斐波那契数列
class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        while(n--) {
            b += a;
            while(b > 1000000007) {
                b -= 1000000007;
                a -= 1000000007;
            }
            a = b - a;
        }
        return a;
    }
};
// 斐波那契数
// 这道题无大树问题
class Solution {
public:
    int fib(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        int a = 0, b = 1;
        while(--N) {
            int temp = a;
            a = b;
            b = temp + a;
        }
        return b;
    }
};
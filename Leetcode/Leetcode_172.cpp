// 阶乘后的零
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        long t = 5;
        while(t <= n) {
            res += n / t;
            t *= 5;
        }
        return res;
    }
};

// 不用 long 解决大数问题
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n > 0) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};
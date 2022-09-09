// 3的幂
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0 || n == 2) return false;
        while (n != 1) {
            if (n % 3 != 0) return false;
            n /= 3;
        }
        return true;
    }
};
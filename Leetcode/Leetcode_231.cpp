// 2的幂
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        double t = n;
        while(t > 1) {
            t = t / 2;
            if(t == 1) return true;
        }
        return false;
    }
};
// 4的幂
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 1) return true;
        long temp = 1;
        while(num > temp) {
            temp *= 4;
            if(num == temp) return true;
        }
        return false;
    }
};
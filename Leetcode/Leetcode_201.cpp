// 数字范围按位与
// 注意是范围
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int move = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++move;
        }
        return n << move;
    }
};
// 爬楼梯
// 动态规划
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, temp;
        while(--n) {
            temp = b;
            b += a;
            a = temp;
        }
        return b;
    }
};
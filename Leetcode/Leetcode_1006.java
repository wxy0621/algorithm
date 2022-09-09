// 笨阶乘
// 状态机 0 1 2 3 表示不同的状态
class Solution {
    public int clumsy(int N) {
        int res = 0;
        int flag = 0;
        int temp = N--;
        boolean isStart = true;
        while (N != 0) {
            if (flag == 0) {
                flag = 1;
                temp *= N;
            } else if (flag == 1) {
                flag = 2;
                temp /= N;
                if (isStart) {
                    res += temp;
                    isStart = false;
                }
                else res -= temp;
            } else if (flag == 2) {
                flag = 3;
                res += N;
            } else {
                flag = 0;
                temp = N;
            }
            --N;
        }
        if (flag == 0 || flag == 1) {
            if (isStart) {
                res += temp;
            } else res -= temp;
        }
        return res;
    }
}
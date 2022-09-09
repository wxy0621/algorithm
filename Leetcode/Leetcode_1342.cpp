// 将数字变成 0 的操作次数
class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        while(num) {
            if(num % 2 != 0) --num;
            else num /= 2;
            ++count;
        }
        return count;
    }
};
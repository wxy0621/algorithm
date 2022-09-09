// 各位相加
// 数学
class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        return (num % 9 == 0) ? 9 : num % 9;
    }
};

// 循环
class Solution2 {
public:
    int addDigits(int num) {
        while(num > 9) {
            num = num / 10 + num % 10;
        }
        return num;
    }
};
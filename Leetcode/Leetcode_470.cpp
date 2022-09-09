// 用 Rand7() 实现 Rand10()
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int num1, num2;
        int temp = 100;
        while (temp > 40) {
            num1 = rand7();
            num2 = rand7();
            temp = num1 + (num2 - 1) * 7;
        }
        return temp % 10 + 1;
    }
};
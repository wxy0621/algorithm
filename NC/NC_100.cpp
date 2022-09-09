// 将字符串转化为整数
class Solution {
public:
    int atoi(string str) {
        long res = 0;
        bool isPositive = true;
        int i = 0;
        while (str[i] == ' ') ++i;
        if (str[i] == '+') {
            isPositive = true;
            ++i;
        } else if (str[i] == '-') {
            isPositive = false;
            ++i;
        }
        while (isdigit(str[i])) {
            res = res * 10 + str[i] - '0';
            if (res > INT_MAX) return isPositive ? INT_MAX : INT_MIN;
            ++i;
        }
        return isPositive ? res : -1 * res;
    }
};
// 整数转罗马数字
class Solution {
public:
    string intToRoman(int num) {
        string res;
        int count = 0;
        int number[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ch[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; i < 13; ++i) {
            while(num - number[i] >= 0) {
                res += ch[i];
                num -= number[i];
            }
        }
        return res;
    }
};
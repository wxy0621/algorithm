// 字符串相加
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int n1 = num1.size(), n2 = num2.size();
        int carry = 0;
        int i = n1 - 1, j = n2 - 1;
        while(i >= 0 && j >= 0) {
            int temp = num1[i] - '0' + num2[j] - '0' + carry;
            carry = temp / 10;
            temp %= 10;
            char c = temp + '0';
            res = c + res;
            --i;
            --j;
        }
        while(i >= 0) {
            int temp = num1[i] - '0' + carry;
            carry = temp / 10;
            temp %= 10;
            char c = temp + '0';
            res = c + res;
            --i;
        }
        while(j >= 0) {
            int temp = num2[j] - '0' + carry;
            carry = temp / 10;
            temp %= 10;
            char c = temp + '0';
            res = c + res;
            --j;
        }
        if(carry) {
            char c = carry + '0';
            res = c + res;
        }
        return res;
    }
};

// 合并
class Solution2 {
public:
    string addStrings(string num1, string num2) {
        string res;
        int n1 = num1.size(), n2 = num2.size();
        int carry = 0;
        int i = n1 - 1, j = n2 - 1;
        while(i >= 0 || j >= 0) {
            int t1 = 0, t2 = 0;
            if(i >= 0) t1 = num1[i] - '0';
            if(j >= 0) t2 = num2[j] - '0';
            int temp = t1 + t2 + carry;
            carry = temp / 10;
            temp %= 10;
            char c = temp + '0';
            res = c + res;
            --i;
            --j;
        }
        if(carry) res = '1' + res;
        return res;
    }
};
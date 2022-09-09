// 大数乘法
// 速度和内存击败了 1% 的对手
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param s string字符串 第一个整数
     * @param t string字符串 第二个整数
     * @return string字符串
     */
    string calculateOneStr(string& s, char& t, int addZeroNum) {
        int n1 = s.size();
        int carry = 0;
        string res = "";
        for (int i = n1 - 1; i >= 0; --i) {
            int temp = carry + (s[i] - '0') * (t - '0');
            res.push_back(temp % 10 + '0');
            carry = temp / 10;
        }
        if (carry != 0) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        for (int i = 0; i < addZeroNum; ++i) {
            res.push_back('0');
        }
        return res;
    }
    void bigAddStr(string& s1, string& s2) {
        string res = "";
        int n1 = s1.size(), n2 = s2.size();
        int i = n1 - 1, j = n2 - 1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int temp = (s1[i] - '0') + (s2[j] - '0') + carry;
            res.push_back(temp % 10 + '0');
            carry = temp / 10;
            --i;
            --j;
        }
        while (i >= 0) {
            int temp = (s1[i] - '0') + carry;
            res.push_back(temp % 10 + '0');
            carry = temp / 10;
            --i;
        }
        while (j >= 0) {
            int temp = (s2[j] - '0') + carry;
            res.push_back(temp % 10 + '0');
            carry = temp / 10;
            --j;
        }
        if (carry != 0) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        s1 = res;
    }
    string solve(string s1, string s2) {
        // write code here
        int n1 = s1.size(), n2 = s2.size();
        string res = "";
        int carry = 0;
        vector<string> addNums(n2);
        for (int i = 0; i < n2; ++i) {
            addNums[i] = calculateOneStr(s1, s2[i], n2 - 1 - i);
        }
        for (int i = 0; i < n2; ++i) {
            bigAddStr(res, addNums[i]);
        }
        return res;
    }
};
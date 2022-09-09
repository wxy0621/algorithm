// 第k个排列
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "123456789";
        s = s.substr(0, n);
        string res;
        --k;
        while(k > 0) {
            int i = k / factorial(n - 1);
            res.push_back(s[i]);
            s.erase(s.begin() + i);
            k %= factorial(n - 1);
            --n;
        }
        return res + s;
    }

    int factorial(int n) {
        int res = 1;
        while(n != 1) {
            res *= n;
            --n;
        }
        return res;
    }
};
// 猜数字游戏
class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        int n = secret.size();
        if (n == 0) return "0A0B";
        int a = 0;
        int b = 0;
        int count1[10] = {0};
        int count2[10] = {0};
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++a;
            } else {
                ++count1[secret[i] - '0'];
                ++count2[guess[i] - '0'];
            }
        }
        for (int i = 0; i < 10; ++i) {
            b += min(count1[i], count2[i]);
        }
        res += to_string(a);
        res += 'A';
        res += to_string(b);
        res += 'B';
        return res;
    }
};
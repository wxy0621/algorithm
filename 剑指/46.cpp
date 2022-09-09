// 把数字翻译成字符串
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        vector<int> dp{1,1};
        string s = to_string(num);
        for(int i = 1; i < s.size(); ++i) {
            if((s[i-1] == '1' && s[i] >= '0' && s[i] <= '9') || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '5')) {
                dp.push_back(dp[i] + dp[i-1]);
            } else {
                dp.push_back(dp[i]);
            }
        }
        return dp.back();

    }
};

int main() {

    return 0;
}
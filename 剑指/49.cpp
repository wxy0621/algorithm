// 丑数，因子只包含2，3，5的数，1也是丑数
// 动态规划法
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res = {1};
        int a = 0, b = 0, c = 0;
        int temp;
        for(int i = 1; i < n; ++i) {
            // 找到下一个最小的丑数，该丑数必然为前面的丑数 * 2或3或5中的一个，按顺序遍历最小的丑数
            temp = min(res[a]*2, res[b]*3);
            temp = min(temp, res[c]*5);
            res.push_back(temp);
            // 若相等则索引前进一位
            if(temp == res[a]*2) ++a;
            if(temp == res[b]*3) ++b;
            if(temp == res[c]*5) ++c;
        }
        return res.back();
    }
};

int main()
{

    return 0;
}
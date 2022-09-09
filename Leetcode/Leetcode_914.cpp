// 卡牌分组
class Solution {
    int cnt[10000];
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        for (int& x: deck) ++cnt[x];
        int g = -1;
        for (int i = 0; i < 10000; ++i) {
            if(cnt[i]) {
                if(g != -1) g = gcd(g, cnt[i]);
                else g = cnt[i];
            }
        }
        return g >= 2;
    }
};
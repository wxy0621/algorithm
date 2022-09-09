// 可怜的小猪
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int res = 0;
        while (pow(((int)(minutesToTest / minutesToDie) + 1), res) < buckets) ++res;
        return res;
    }
};
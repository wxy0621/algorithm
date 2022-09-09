// 第一个错误的版本
// 二分法
class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while(i < j) {
            int mid = i + (j - i) / 2;
            if(!isBadVersion(mid)) i = mid + 1;
            else j = mid;
        }
        return i;
    }
};
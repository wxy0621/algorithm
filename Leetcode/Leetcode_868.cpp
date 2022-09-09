// 二进制间距
class Solution {
public:
    int binaryGap(int n) {
        int res = 0;
        vector<int> temp;
        while(n != 0) {
            temp.emplace_back(n % 2);
            n /= 2;
        }
        int last = temp.size() - 1;
        for(int i = temp.size() - 2; i >= 0; --i) {
            if(temp[i] == 1) {
                res = max(res, last - i);
                last = i;
            }
        }
        return res;
    }
};
// 回文数
// 自己写的怎么总那么麻烦
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> res;
        while(x != 0) {
            res.emplace_back(x % 10);
            x /= 10;
        }
        int i = 0, j = res.size() - 1;
        while(i < j) {
            if(res[i] != res[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};

// return 语句的前半句是 3223 这种情况，return 语句后半句是 323 这种情况
class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reverse = 0;
        while(x > reverse) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return x == reverse || x == reverse / 10;
    }
};
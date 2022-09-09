// 加一
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n - 1; i >= 0; --i) {
            if(digits[i] != 9) {
                ++digits[i];
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        vector<int> res(n, 0);
        res.insert(res.begin(), 1);
        return res;
    }
};

// 不知道啥方法
class Solution2 {
public:
    vector<int> plusOne(vector<int>& carry) {
        int n = carry.size();
        if (n == 0) return {};
        int isCarry = 0;
        int tempSum;
        for (int i = n - 1; i >= 0; --i) {
            tempSum = isCarry + carry[i];
            if (i == n - 1) tempSum += 1;
            carry[i] = tempSum % 10;
            isCarry = tempSum / 10;
        }
        vector<int> res(n+1, 0);
        res[0] = 1;
        if (isCarry == 1) return res;
        return carry;
    }
};
// 可被 5 整除的二进制前缀
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<bool> res(n, false);
        int i = 0, temp = 0;
        for(auto& num: A) {
            temp = temp * 2 + num;
            if(temp % 5 == 0) res[i] = true;
            ++i;
            temp %= 5; // 否则会溢出
        }
        return res;
    }
};
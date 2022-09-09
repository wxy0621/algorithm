// 杨辉三角 II
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for(int i = 1; i <= rowIndex; ++i)  {
            // 必须从后往前遍历，不然该步的 res[j - 1] 已经在for循环的上一次改变了
            for(int j = i; j >= 1; --j) {
                if(j == i) res[j] = 1;
                else res[j] = res[j - 1] + res[j];
            }
        }
        return res;
    }
};
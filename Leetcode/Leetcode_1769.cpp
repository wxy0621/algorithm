// 移动所有球到每个盒子所需的最小操作数
// dp
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        int operations = 0;
        int left = boxes[0] - '0';
        int right = 0;
        for (int i = 1; i < n; ++i) {
            if (boxes[i] == '1') {
                ++right;
                operations += i;
            }
        }
        res[0] = operations;
        for (int i = 1; i < n; ++i) {
            operations += left - right;
            res[i] = operations;
            if (boxes[i] == '1') {
                ++left;
                --right;
            }
        }
        return res;
    }
};
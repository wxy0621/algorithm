// 有序数组中出现次数超过25%的元素
// 遍历
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int res = arr[0], cur = arr[0], cur_count = 1, max_count = INT_MIN, n = arr.size();
        for(int i = 1; i < n; ++i) {
            if(arr[i] != cur) {
                if(cur_count > max_count) {
                    max_count = cur_count;
                    res = cur;
                }
                cur = arr[i];
                cur_count = 1;
            } else {
                ++cur_count;
            }
        }
        if(cur_count > max_count) {
            max_count = cur_count;
            res = cur;
        }
        return res;
    }
};
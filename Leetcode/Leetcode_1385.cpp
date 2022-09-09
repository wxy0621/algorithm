// 两个数组间的距离值
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int len_arr1 = arr1.size(), len_arr2 = arr2.size();
        int res = 0;
        for(int i = 0; i < len_arr1; ++i) {
            bool flag = true;
            for(int j = 0; j < len_arr2; ++j) {
                if(abs(arr1[i] - arr2[j]) <= d) {
                    flag = false;
                    break;
                }
            }
            if(flag) ++res;
        }
        return res;
    }
};
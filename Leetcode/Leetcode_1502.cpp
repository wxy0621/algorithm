// 判断能否形成等差数列
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int dif = arr[1] - arr[0];
        for(int i = 1; i < n - 1; ++i) {
            if(dif != (arr[i+1] - arr[i])) return false;
        }
        return true;
    }
};
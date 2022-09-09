// 区域和检索 - 数组不可变
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr.resize(n+1);
        arr[0] = 0;
        for (int i = 0; i < n; ++i) {
            arr[i+1] = arr[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return arr[j+1] - arr[i];
    }
private:
    vector<int> arr;
};
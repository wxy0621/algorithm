// 下一个更大元素 II
// 单调栈
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> res(n, -1);
        // 因为是循环数组，所以执行两编
        for(int i = n - 1; i >= 0; --i) {
            while(!s.empty() && nums[i] >= s.top()) {
                s.pop();
            }
            if(!s.empty()) {
                res[i] = s.top();
            }
            s.push(nums[i]);
        }
        for(int i = n - 1; i >= 0; --i) {
            while(!s.empty() && nums[i] >= s.top()) {
                s.pop();
            }
            if(!s.empty()) {
                res[i] = s.top();
            }
            s.push(nums[i]);
        }
        return res;
    }
};
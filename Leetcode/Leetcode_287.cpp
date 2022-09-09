// 寻找重复数
// 快慢指针
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow)
                break;
        }
        int temp = 0;
        while(true) {
            temp = nums[temp];
            slow = nums[slow];
            if(temp == slow) 
                break;
        }
        return slow;
    }
};
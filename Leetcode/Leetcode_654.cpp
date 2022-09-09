// 最大二叉树
// 递归
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        int max_index = start;
        for(int i = start + 1; i <= end; ++i) {
            if(nums[i] > nums[max_index]) max_index = i;
        }
        TreeNode* res = new TreeNode(nums[max_index]);
        res->left = helper(nums, start, max_index - 1);
        res->right = helper(nums, max_index + 1, end);
        return res;
    }
};
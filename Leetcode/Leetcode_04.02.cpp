// 最小高度树
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, 0, n);
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if(left == right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};
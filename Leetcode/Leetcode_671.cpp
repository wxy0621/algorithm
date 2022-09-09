// 二叉树中第二小的节点
// 根节点必然是最小的那个节点，因此只要找到左右子树和根节点不同的那个，且最小的那个就行了
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        return helper(root, root->val);
    }
    int helper(TreeNode* root, int val) {
        if(!root) return -1;
        if(root->val > val) return root->val;
        int left = helper(root->left, val);
        int right = helper(root->right, val);
        if(left < 0) return right;
        if(right < 0) return left;
        return min(left, right);
    } 
};
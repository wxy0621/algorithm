// 二叉树中的最大路径和
class Solution {
public:
    int maxPathSum(TreeNode* root, int &val) {
	    if(root == nullptr) return 0;
        int left = maxPathSum(root->left, val);
        int right = maxPathSum(root->right, val);
        // 总共三种情况，包含在 lmr 和 ret 中
        //（左 中 右）路，不再往上走
        int lmr = root->val + max(0, left) + max(0, right);
        // 选左右中大的一条路径，再网上返回
        int ret = root->val + max(0, max(left, right));
        // val 始终保存已经存过的最大值，所以不必在意这个返回值 ret，这个返回值只是返回上一级
        val = max(val, max(lmr, ret));
        return ret;
    }

    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSum(root, val);
	    return val;
    }
};
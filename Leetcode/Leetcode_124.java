// 二叉树中的最大路径和
// 想法好
class Solution {
    public int res;
    public int maxPathSum(TreeNode root) {
        res = Integer.MIN_VALUE;;
        dfs(root);
        return res;
    }
    public int dfs(TreeNode root) {
        if (root == null) return 0;
        int left = Math.max(dfs(root.left), 0);
        int right = Math.max(dfs(root.right), 0);
        res = Math.max(res, left + right + root.val);
        return Math.max(left, right) + root.val;
    }
}
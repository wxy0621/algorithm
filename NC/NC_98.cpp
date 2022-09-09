// 判断 t1 树的子树是否有和 t2 树一样的拓扑结构（值也要相等）
class Solution {
public:
    /**
     * 
     * @param root1 TreeNode类 
     * @param root2 TreeNode类 
     * @return bool布尔型
     */
    bool isContains(TreeNode* root1, TreeNode* root2) {
        // write code here
        if (!root1) return false;
        return helper(root1, root2) || isContains(root1->left, root2) || isContains(root1->right, root2);
    }
    bool helper(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2 || root1->val != root2->val) return false;
        return helper(root1->left, root2->left) && helper(root1->right, root2->right);
    }
};
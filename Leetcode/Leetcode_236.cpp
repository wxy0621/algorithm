// 二叉树的最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 若叶子节点->返回空，若是则p或q返回该节点
        if(root == nullptr || p == root || q == root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 4种情况，可以合并为3种：
        // 1.若左空，则返回右；若右空，则返回做；左右都空，返回空（已合并入第一句话）；左右都非空，说明p、q位于root的左右两端，则返回root
        if(left == nullptr) return right;
        if(right = nullptr) return left;
        return root;
    }
};
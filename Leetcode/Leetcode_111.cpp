// 二叉树的最小深度
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        // 底部必须是从叶子节点开始，四种情况的其中三种合并为下面这个 if 语句
        if(root->left == nullptr || root->right == nullptr) {
            return left + right + 1;
        }
        return 1 + min(left , right);
    }
};
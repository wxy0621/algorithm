// 打家劫舍 III
// 爷爷 + 四个孙子 和 两个儿子 谁的钱多
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = root->val;
        if(root->left) res += rob(root->left->left) + rob(root->left->right);
        if(root->right) res += rob(root->right->left) + rob(root->right->right);

        return max(res, rob(root->left) + rob(root->right));
    }
};

// pair对 保存每个节点 被选择或是不被选择， first 表示不被选择， second 表示被选择
// 当节点被选择时，则子节点一定不被选择，当节点不被选择时，则节点可以被选择也可以不被选择（选其中大的）
class Solution2 {
public:
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        pair<int, int> res = helper(root);
        return max(res.first, res.second);
    }
    pair<int, int> helper(TreeNode* root) {
        if(root == nullptr) return make_pair(0, 0);
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        return make_pair(max(left.first, left.second) + max(right.first, right.second), root->val + left.first + right.first);
    }
};
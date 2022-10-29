// 二叉搜索树中的中序后继
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (pre == p) {
                return cur;
            }
            pre = cur;
            cur = cur->right;
        }
        return nullptr;
    }
};
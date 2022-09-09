// 另一个树的子树
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s, t);
    }

    bool dfs(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        return helper(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }

    bool helper(TreeNode* s , TreeNode* t) {
        if(!s && !t) return true;
        if((!s && t) || (s && !t) || (s->val != t->val)) return false;
        return helper(s->left, t->left) && helper(s->right, t->right);
    }
};
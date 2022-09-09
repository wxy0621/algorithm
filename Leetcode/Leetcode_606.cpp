// 根据二叉树创建字符串
// dfs，重点是如何加括号，如何添加判断条件
class Solution {
public:
    string res;
    string tree2str(TreeNode* t) {
        if(!t) return res;
        dfs(t);
        return res;
    }
    void dfs(TreeNode* t) {
        if(!t) return;
        res += to_string(t->val);
        if(t->left || t->right) {
            res += '(';
            dfs(t->left);
            res += ')';
        }
        if(t->right) {
            res += '(';
            dfs(t->right);
            res += ')';
        }
    }
};
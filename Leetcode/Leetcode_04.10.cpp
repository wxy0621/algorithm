// 检查子树
class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (!t1 || !t2) return false;
        return check(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }
    bool check(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        if (t1->val != t2->val) return false;
        return check(t1->left, t2->left) && check(t1->right, t2->right);
    }
};
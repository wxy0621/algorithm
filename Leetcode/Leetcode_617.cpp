// 合并二叉树
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr) return t2;
        if(t2 == nullptr) return t1;

        TreeNode* res = new TreeNode(t1->val + t2->val);
        res->left = mergeTrees(t1->left, t2->left);
        res->right = mergeTrees(t1->right, t2->right);

        return res;
    }
};

// 直接用 t1
class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr) return t2;
        if(t2 == nullptr) return t1;

        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};
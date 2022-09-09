// 二叉搜索树的最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if(root->val > p->val && root->val > q->val) root = root->left;
            else if(root->val < p->val && root->val < q->val) root = root->right;
            else break;
        }
        return root;
    }
};

// 改版速度快些
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < q->val) {
            TreeNode* temp = q;
            q = p;
            p = temp;
        }
        while(root) {
            if(root->val > p->val) root = root->left;
            else if(root->val < q->val) root = root->right;
            else break;
        }
        return root;
    }
};

// 递归
class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
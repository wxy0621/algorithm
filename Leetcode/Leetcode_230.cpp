// 二叉搜索树中第K小的元素
// 递归
class Solution {
public:
    int res = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode* root, int& k) {
        if(root == nullptr) return;
        dfs(root->left, k);
        if(--k == 0) res = root->val;
        dfs(root->right, k);
    }
};

// 迭代
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p != nullptr || !s.empty()) {
            while(p != nullptr) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if(--k == 0) return p->val;
            p = p->right;
        }
        return -1;
    }
};
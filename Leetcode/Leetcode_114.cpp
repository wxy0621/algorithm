// 二叉树展开为链表
// 递归
class Solution {
public:
    void flatten(TreeNode* root) {
        dfs(root, nullptr);
    }
    TreeNode* dfs(TreeNode* root, TreeNode* pre) {
        if(root == nullptr) return pre;
        pre = dfs(root->right, pre);
        pre = dfs(root->left, pre);
        root->right = pre;
        root->left = nullptr;
        return root;
    }
};

// 迭代
class Solution2 {
public:
    void flatten(TreeNode* root) {
        while(root != nullptr) {
            if(root->left == nullptr) {
                root = root->right;
            } else {
                TreeNode* pre = root->left;
                while(pre->right != nullptr) {
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }  
};
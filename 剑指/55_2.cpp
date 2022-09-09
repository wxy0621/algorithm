// 平衡二叉树，定义：一棵树的左右子树的深度插值不超过 1

// 自底向上
class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
    int helper(TreeNode* node) {
        if (!node) return 0;
        int left = helper(node->left);
        if (left == -1) return -1;
        int right = helper(node->right);
        if (right == -1) return -1;
        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    }
};

// 重复次数太多，自顶向下
class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(helper(root->left) - helper(root->right)) <= 1;
    }
    
    int helper(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(helper(root->left), helper(root->right));
    }
};

// 啥奇怪的方法？
class Solution3 {
public:
    bool isBalanced(TreeNode* root) {
        int res = 0;
        return isBalanced(root, &res);
    }
    bool isBalanced(TreeNode* root, int* depth) {
        if(root == nullptr) {
            *depth = 0;
            return true;
        }

        int left = 0, right = 0;
        if(isBalanced(root->left, &left) && isBalanced(root->right, &right)) {
            int diff = left - right;
            if(diff <= 1 && diff >= -1) {
                *depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        
        return false;
    }
};
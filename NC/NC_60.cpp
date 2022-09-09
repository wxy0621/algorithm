// 判断一棵树是否为二叉搜索树和完全二叉树
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        vector<bool> res;
        res.emplace_back(searchTree(root, INT_MIN, INT_MAX));
        res.emplace_back(completeTree(root));
        return res;
    }
    bool searchTree(TreeNode* root, int left, int right) {
        if (!root) return true;
        if (left > root->val || root->val > right) return false;
        return searchTree(root->left, left, root->val) && searchTree(root->right, root->val, right);
    }
    bool completeTree(TreeNode* root) {
        if (!root) return true;
        if (!root->left && root->right) return false;
        if (root->left && !root->right) return completeTree(root->left);
        return completeTree(root->left) && completeTree(root->right);
    }
};
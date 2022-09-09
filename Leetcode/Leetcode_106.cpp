// 从中序与后序遍历序列构造二叉树
class Solution {
public:
    unordered_map<int, int> m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0) return nullptr;
        // 存放 inorder 的索引，通过索引来过渡
        for(int i = 0; i < n; ++i) m[inorder[i]] = i;
        return helper(inorder, postorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inl, int inr, int pol, int por) {
        if(inl > inr) return nullptr;
        TreeNode* root = new TreeNode(postorder[por]);
        int k = m[postorder[por]];
        root->left = helper(inorder, postorder, inl, k - 1, pol, k - 1 - inl + pol);
        root->right = helper(inorder, postorder, k + 1, inr, pol + k - inl, por - 1);
        return root;
    }
};
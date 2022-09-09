// 从前序和中序遍历序列构造二叉树
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return nullptr;
        TreeNode* res;
        helper(res, preorder, inorder);
        return res;
    }
    
    void helper(TreeNode* & res, vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return;
        
        res = new TreeNode(preorder[0]);

        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), preorder[0]);
        int dif = iter - inorder.begin();
        preorder.erase(preorder.begin());

        vector<int> left_order(inorder.begin(), inorder.begin() + dif);

        helper(res->left, preorder, left_order);
        // 因为上一步 helper erase 的是 left_order，所以之后 inorder 仍然要处理掉前面的全部左子树
        inorder.erase(inorder.begin(), inorder.begin() + dif + 1);
        helper(res->right, preorder, inorder);
    }
};

// 保存 inorder 索引位置，通过索引位置逆推两个 vector 的起始位置
class Solution2 {
public:
    unordered_map<int, int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) return nullptr;
        for(int i = 0; i < n; ++i) m[inorder[i]] = i;
        return helper(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2) {
        if(l1 > r1) return nullptr;
        TreeNode* root = new TreeNode(preorder[l1]);
        int k = m[preorder[l1]];
        root->left = helper(preorder, inorder, l1 + 1, k - l2 + l1, l2, k - 1);
        root->right = helper(preorder, inorder, k + 1 - r2  + r1, r1, k + 1, r2);
        return root;
    }
};
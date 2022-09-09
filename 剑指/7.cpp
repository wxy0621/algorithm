// 重建二叉树，根据前序和中序遍历重建二叉树
#include <bits/stdc++.h>

using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* p;
        if(preorder.empty())
            return nullptr;
        buildWholeTree(p, preorder, inorder);
        return p;
    }
    void buildWholeTree(TreeNode* &p, vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.empty())
            return;
        if(inorder.empty())
            return;
        
        // 根节点为前序遍历的第一个数
        p = new TreeNode(preorder[0]);
        // 找到根节点在中序遍历中的位置，左边为左子树，右边为右子树
        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), preorder[0]);
        int res = iter - inorder.begin();

        // 删除前序遍历的跟节点
        preorder.erase(preorder.begin());

        // 建立中序遍历中的左子树
        vector<int>::const_iterator first_left = inorder.begin();
        vector<int>::const_iterator end_left = inorder.begin() + res;
        vector<int> left_inorder(first_left, end_left);

        // left_inorder为中序遍历的左子树
        buildWholeTree(p->left, preorder, left_inorder);
        inorder.erase(inorder.begin(), inorder.begin() + res + 1);
        buildWholeTree(p->right, preorder, inorder);
        
    }
};

// 查找左右子树的开始和结束节点
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res;
        int n = preorder.size();
        res = helper(preorder, inorder, 0 , n-1, 0, n-1);
        return res;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2) {
        if (l1 > r1) return nullptr;
        TreeNode* root = new TreeNode(preorder[l1]);
        int i = l2;
        while (inorder[i] != preorder[l1]) {
            ++i;
        }
        root->left = helper(preorder, inorder, l1+1, l1+1+(i-l2-1), l2, i-1);
        root->right = helper(preorder, inorder, l1+1+(i-l2), r1, i+1, r2);
        return root;
    }
};
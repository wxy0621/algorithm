#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        if(root->left == nullptr && root->right == nullptr)
            return root;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);

        return root;
    }
};

class Solution2 {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        return helper(root);
    }
    
    TreeNode* helper(TreeNode* root) {
        if(!root) return nullptr;
        swap(root->left, root->right);
        helper(root->left);
        helper(root->right);
        return root;
    }
};

class Solution3 {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* temp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(temp);
        return root;
    }
};

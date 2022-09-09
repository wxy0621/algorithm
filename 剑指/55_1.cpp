// 二叉树的深度
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int left_num = maxDepth(root->left);
        int right_num = maxDepth(root->right);

        return (left_num > right_num ? left_num : right_num) + 1;
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{

    return 0;
}
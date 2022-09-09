#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 == nullptr || root2 == nullptr)
            return false;
        if(root1->val != root2->val)
            return false;

        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
};

int main()
{



    return 0;
}
// 树的子结构
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr)
            return false;
        
        return helper(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool helper(TreeNode* A, TreeNode* B) {
        if(B == nullptr)
            return true;
        else if(A == nullptr)
            return false;
        if(A->val != B->val)
            return false;

        return helper(A->left, B->left) && helper(A->right, B->right);
    }
};

int main()
{
    
    return 0;
}
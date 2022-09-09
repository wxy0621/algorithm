#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() != 0)
        {
            TreeNode* tmp = q.front();
            q.pop();
            res.push_back(tmp->val);
            if(tmp->left != nullptr)
                q.push(tmp->left);
            if(tmp->right != nullptr)
                q.push(tmp->right);
        }
        return res;
    }
};

int main()
{
    return 0;
}
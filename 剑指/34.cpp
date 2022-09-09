#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector< vector<int> > res;
        vector<int> path;
        if(root == nullptr)
            return res;
        int currentSum = 0;
        FindPath(root, sum, res, path, currentSum);
        return res;
    }

    void FindPath(TreeNode* root, int sum, vector< vector<int> >& res, vector<int>& path, int currentSum) {
        currentSum += root->val;
        path.push_back(root->val);

        bool isLeaf = (root->left == nullptr) && (root->right == nullptr);
        if(currentSum == sum && isLeaf)
        {
            res.push_back(path);
        }


        if(root->left != nullptr)
            FindPath(root->left, sum, res, path, currentSum);
        if(root->right != nullptr)
            FindPath(root->right, sum, res, path, currentSum);
        
        path.pop_back();
    }
};

int main()
{

    return 0;
}
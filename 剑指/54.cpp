// 二叉搜索树的第k大节点
// 中序遍历，二叉搜索树的左子树都比节点值小，右子树都比节点值大
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int res;
        dfs(root, k, res);
        return res;
    }

    void dfs(TreeNode* root, int& k, int& res) {
        // 若是空节点则返回上一级
        if(root == nullptr) return;
        // 先遍历右子树，若遍历完 k 已经为 0 则返回上一级
        dfs(root->right, k, res);
        if(k == 0) return;
        // 主要步骤，每遍历一个节点 k 减少 1 若是零则将 res 返回
        k--;
        if(k == 0) res = root->val;
        // 继续遍历左子树
        dfs(root->left, k, res);
    }
};

class Solution2 {
public:
    vector<int> res;
    int kthLargest(TreeNode* root, int k) {
        if(!root) return -1;
        dfs(root);
        int n = res.size();
        return res[n - k];
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        res.emplace_back(root->val);
        dfs(root->right);
    }
};

int main()
{

    return 0;
}
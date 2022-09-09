// 二叉树的所有路径
// 递归
class Solution {
public:
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        string temp;
        helper(root, temp);
        return res;
    }

    void helper(TreeNode* root, string temp) {
        if(!root) return;
        temp += to_string(root->val) + "->";
        if(root->left == nullptr && root->right == nullptr) {
            temp.erase(temp.end() - 2, temp.end());
            res.emplace_back(temp);
        }
        helper(root->left, temp);
        helper(root->right, temp);
    }
};

// 小改
class Solution2 {
public:
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return { };
        string temp;
        helper(root, temp);
        return res;
    }
    void helper(TreeNode* root, string temp) {
        if(!root) return;
        temp += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            res.emplace_back(temp);
            return;
        }
        temp += "->";
        helper(root->left, temp);
        helper(root->right, temp);
    }
};
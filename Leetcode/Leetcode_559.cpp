// N叉树的最大深度
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        return helper(root);
    }

    int helper(Node* root) {
        if(!root) return 0;

        int res = 0;
        for(int i = 0; i < root->children.size(); ++i) {
            res = max(res, helper(root->children[i]));
        }
        return res + 1;
    }
};

// 改版
class Solution2 {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int depth = 0;
        for(auto& t: root->children) depth = max(depth, maxDepth(t));
        return depth + 1;
    }
};
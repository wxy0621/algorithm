// 前序遍历构造二叉搜索树
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* res;
        res = preOrder(preorder, 0, preorder.size()-1);
        return res;
    }
    TreeNode* preOrder(const vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;
        TreeNode* newNode = new TreeNode(preorder[start]);
        int temp = start+1;
        for (int i = start+1; i < preorder.size(); ++i) {
            if (preorder[start] < preorder[temp]) {
                break;
            } else {
                ++temp;
            }
        }
        newNode->left = preOrder(preorder, start+1, temp-1);
        newNode->right = preOrder(preorder, temp, end);
        return newNode;
    }
};
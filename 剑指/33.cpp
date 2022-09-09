#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        // 二叉搜索树的左子树一定比根节点小
        // 二叉搜索树的右子树一定比根节点大
        if(postorder.empty())
            return true;
        bool res = true;
        res = helper(postorder, 0, postorder.size() - 1);
        return res;
    }

    bool helper(vector<int>& postorder, int start, int end)
    {
        int root = postorder[end];

        int i = start;
        for(; i < end; ++i) {
            if(postorder[i] > root)
                break;
        }

        for(int j = i; j < end; ++j) {
            if(postorder[j] < root)
                return false;
        }

        // 若i = start 则无左子树
        bool left = true;
        if(i > start)
            left = helper(postorder, start, i - 1);
        
        // 若i = end - 1 则无右子树
        bool right = true;
        if(i < end - 1)
            right = helper(postorder, i, end - 1);

        return left && right;
        
    }
};

// 改版2
class Solution2 {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        if (n == 0) return true;
        return helper(postorder, 0, n - 1);
    }
    bool helper(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;
        int rootVal = postorder[right];
        int i;
        for (i = left; i < right; ++i) {
            if (postorder[i] == rootVal) return false;
            else if (postorder[i] > rootVal) break;
        }
        for (int j = i; j < right; ++j) {
            if (postorder[j] <= rootVal) return false;
        }
        return helper(postorder, left, i-1) && helper(postorder, i, right-1);
    }
};
// 二叉搜索树与双向链表
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Node* pre;
    Node* head;
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void dfs(Node* cur) {
        if(cur == nullptr)
            return;
        dfs(cur->left);
        if(pre != nullptr)
            pre->right = cur;
        else
            head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};

int main()
{
    return 0;
}
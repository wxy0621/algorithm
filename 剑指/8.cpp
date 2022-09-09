// 二叉树的下一个节点
// 和正常二叉树不同，还包含了指向父节点的指针 next
#include <bits/stdc++.h>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) { }
};
  
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr) return nullptr;
        
        if(pNode->right) {
            pNode = pNode->right;
            while(pNode->left != nullptr) {
                pNode = pNode->left;
            }
            return pNode;
        }
        
        while(pNode->next) {
            if(pNode->next->left == pNode)
                return pNode->next;
            pNode = pNode->next;
        }
        return nullptr;
    }
};

int main()
{
    return 0;
}